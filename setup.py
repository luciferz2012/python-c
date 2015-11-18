#!/usr/bin/env python
# -*- coding: utf-8 -*-
from os.path import abspath

from vcxproj import end, VcxProj

__author__ = 'Luciferz2012'

py32 = 'C:\\Program Files (x86)\\Python 3.5'
py64 = 'C:\\Program Files\\Python 3.5'
pylib_debug = 'python35_d.lib'
pylib_release = 'python35.lib'

py = {
    'Debug|Win32': {
        'include_dirs': py32 + '\\include',
        'libs': py32 + '\\libs\\' + pylib_debug
    },
    'Release|Win32': {
        'include_dirs': py32 + '\\include',
        'libs': py32 + '\\libs\\' + pylib_release
    },
    'Debug|x64': {
        'include_dirs': py64 + '\\include',
        'libs': py64 + '\\libs\\' + pylib_debug
    },
    'Release|x64': {
        'include_dirs': py64 + '\\include',
        'libs': py64 + '\\libs\\' + pylib_release
    }
}

c2python = {
    'Debug|Win32': {
        'post_build_command': 'copy /y $(ProjectDir)great_module.py $(OutDir)great_module.py'
    },
    'Release|Win32': {
        'post_build_command': 'copy /y $(ProjectDir)great_module.py $(OutDir)great_module.py'
    },
    'Debug|x64': {
        'post_build_command': 'copy /y $(ProjectDir)great_module.py $(OutDir)great_module.py'
    },
    'Release|x64': {
        'post_build_command': 'copy /y $(ProjectDir)great_module.py $(OutDir)great_module.py'
    }
}

# change configuration type to .dll
# change target extension to .pyd
python2c = {
    'Debug|Win32': {
        'post_build_command': 'copy /y $(ProjectDir)runme.py $(OutDir)runme.py' +
                                end + '"' + py32 + '\\python.exe" $(OutDir)runme.py'
    },
    'Release|Win32': {
        'post_build_command': 'copy /y $(ProjectDir)runme.py $(OutDir)runme.py' +
                                end + '"' + py32 + '\\python.exe" $(OutDir)runme.py'
    },
    'Debug|x64': {
        'post_build_command': 'copy /y $(ProjectDir)runme.py $(OutDir)runme.py' +
                                end + '"' + py64 + '\\python.exe" $(OutDir)runme.py'
    },
    'Release|x64': {
        'post_build_command': 'copy /y $(ProjectDir)runme.py $(OutDir)runme.py' +
                                end + '"' + py64 + '\\python.exe" $(OutDir)runme.py'
    }
}

def main(target, setting_pack):
    vcx = VcxProj(target)
    for settings in setting_pack:
        vcx.add_by_settings(settings)
    vcx.write(target)

if __name__ == '__main__':
    main('C2Python\\C2Python.vcxproj', [py, c2python])
    main('Python2C\\Python2C.vcxproj', [py, python2c])
