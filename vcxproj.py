#!/usr/bin/env python
# -*- coding: utf-8 -*-
from codecs import open as _open
from xml.etree.ElementTree import fromstring, tostring, SubElement

__author__ = 'Luciferz2012'

end = '\n'

# xxx get from vcxproj file
DECLARATION = '<?xml version="1.0" encoding="utf-8"?>' + end
NS = 'http://schemas.microsoft.com/developer/msbuild/2003'


class Schema:
    def __init__(self, group, item, default=';', sep=';'):
        self.group = group
        self.item = item
        self.default = default
        self.sep = sep
        if default == sep:
            self.default = '%%(%s)' % item


SCHEMA_MAP = {
    'include_dirs': Schema('ClCompile', 'AdditionalIncludeDirectories'),
    'prep_defs': Schema('ClCompile', 'PreprocessorDefinitions'),
    'lib_dirs': Schema('Link', 'AdditionalLibraryDirectories'),
    'libs': Schema('Link', 'AdditionalDependencies'),
    'post_build_command': Schema('PostBuildEvent', 'Command', 'echo Post build command is done', end)
}


class VcxProj:
    def __init__(self, file_path):
        xml = _open(file_path, encoding='utf-8').read().replace(' xmlns="%s"' % NS, '')
        self.root = fromstring(xml)
        self.root.set('xmlns', NS)

    def write(self, file_path):
        file = open(file_path, 'w')
        file.writelines(DECLARATION)
        file.write(tostring(self.root, method='xml').decode('utf-8'))

    def add(self, config, key, values):
        schema = SCHEMA_MAP.get(key)
        if schema:
            item = self._key_func(config, schema)
            new_list = values.split(schema.sep)
            old_list = item.text.split(schema.sep)
            item.text = schema.sep.join(list(set(new_list) - set(old_list)) + old_list)
            return item.text
        else:
            print('%s: not implemented')

    def add_by_settings(self, settings):
        for platform, configs in settings.items():
            config = self.config(platform)
            if config:
                for key, values in configs.items():
                    self.add(config, key, values)
            else:
                print('%s: not found' % platform)
        return self

    def config(self, platform):
        return self.root.find(".//ItemDefinitionGroup[@Condition=\"'$(Configuration)|$(Platform)'=='%s'\"]" % platform)

    @staticmethod
    def _get_child(node, tag, text=''):
        child = node.find(tag)
        if child is None:
            child = SubElement(node, tag)
            child.text = text
        return child

    def _key_func(self, config, schema):
        return self._get_child(self._get_child(config, schema.group), schema.item, schema.default)


def main(target):
    ifcengine = {
        'Debug|Win32': {
            'include_dirs': 'ref\\ifcengine\\include',
            'lib_dirs': 'ref\\ifcengine\\lib32',
            'libs': 'ifcengine.lib',
            'prep_defs': 'WIN32;_WINDOWS;_DEBUG',
            'post_build_command': 'copy /y $(SolutionDir)ref\\ifcengine\\bin32\\ifcengine.dll $(OutDir)ifcengine.dll' +
                                  end + 'copy /y $(SolutionDir)ref\\ifcengine\\data\\* $(OutDir)*'
        },
        'Release|Win32': {
            'include_dirs': 'ref\\ifcengine\\include',
            'lib_dirs': 'ref\\ifcengine\\lib32',
            'libs': 'ifcengine.lib',
            'prep_defs': 'WIN32;_WINDOWS;NDEBUG',
            'post_build_command': 'copy /y $(SolutionDir)ref\\ifcengine\\bin32\\ifcengine.dll $(OutDir)ifcengine.dll' +
                                  end + 'copy /y $(SolutionDir)ref\\ifcengine\\data\\* $(OutDir)*'
        },
        'Debug|x64': {
            'include_dirs': 'ref\\ifcengine\\include',
            'lib_dirs': 'ref\\ifcengine\\lib64',
            'libs': 'ifcengine.lib',
            'prep_defs': 'WIN64;_WINDOWS;_DEBUG',
            'post_build_command': 'copy /y $(SolutionDir)ref\\ifcengine\\bin64\\ifcengine.dll $(OutDir)ifcengine.dll' +
                                  end + 'copy /y $(SolutionDir)ref\\ifcengine\\data\\* $(OutDir)*'
        },
        'Release|x64': {
            'include_dirs': 'ref\\ifcengine\\include',
            'lib_dirs': 'ref\\ifcengine\\lib64',
            'libs': 'ifcengine.lib',
            'prep_defs': 'WIN64;_WINDOWS;NDEBUG',
            'post_build_command': 'copy /y $(SolutionDir)ref\\ifcengine\\bin64\\ifcengine.dll $(OutDir)ifcengine.dll' +
                                  end + 'copy /y $(SolutionDir)ref\\ifcengine\\data\\* $(OutDir)*'
        }
    }
    coin = {
        'Debug|Win32': {
            'include_dirs': 'ref\\coin\\include',
            'lib_dirs': 'ref\\coin\\lib32',
            'libs': 'coin3d.lib;sowin1d.lib',
            'prep_defs': 'COIN_DLL;SOWIN_DLL;WIN32;_WINDOWS;_DEBUG',
            'post_build_command': 'copy /y $(SolutionDir)ref\\coin\\bin32\\coin3d.dll $(OutDir)coin3d.dll' +
                                  end + 'copy /y $(SolutionDir)ref\\coin\\bin32\\sowin1d.dll $(OutDir)sowin1d.dll'
        },
        'Release|Win32': {
            'include_dirs': 'ref\\coin\\include',
            'lib_dirs': 'ref\\coin\\lib32',
            'libs': 'coin3.lib;sowin1.lib',
            'prep_defs': 'COIN_DLL;SOWIN_DLL;WIN32;_WINDOWS;NDEBUG',
            'post_build_command': 'copy /y $(SolutionDir)ref\\coin\\bin32\\coin3.dll $(OutDir)coin3.dll' +
                                  end + 'copy /y $(SolutionDir)ref\\coin\\bin32\\sowin1.dll $(OutDir)sowin1.dll'
        },
        'Debug|x64': {
            'include_dirs': 'ref\\coin\\include',
            'lib_dirs': 'ref\\coin\\lib64',
            'libs': 'coin3d.lib;sowin1d.lib',
            'prep_defs': 'COIN_DLL;SOWIN_DLL;WIN64;_WINDOWS;_DEBUG',
            'post_build_command': 'copy /y $(SolutionDir)ref\\coin\\bin64\\coin3d.dll $(OutDir)coin3d.dll' +
                                  end + 'copy /y $(SolutionDir)ref\\coin\\bin64\\sowin1d.dll $(OutDir)sowin1d.dll'
        },
        'Release|x64': {
            'include_dirs': 'ref\\coin\\include',
            'lib_dirs': 'ref\\coin\\lib64',
            'libs': 'coin3.lib;sowin1.lib',
            'prep_defs': 'COIN_DLL;SOWIN_DLL;WIN64;_WINDOWS;NDEBUG',
            'post_build_command': 'copy /y $(SolutionDir)ref\\coin\\bin64\\coin3.dll $(OutDir)coin3.dll' +
                                  end + 'copy /y $(SolutionDir)ref\\coin\\bin64\\sowin1.dll $(OutDir)sowin1.dll'
        }
    }
    VcxProj(target).add_by_settings(ifcengine).add_by_settings(coin).write(target)


if __name__ == '__main__':
    from sys import argv
    from shutil import copy

    if len(argv) > 1:
        path = argv[1]
        copy(path, path + '.old')
        main(path)
    else:
        print('Usage: vcxproj target.vcxproj')
