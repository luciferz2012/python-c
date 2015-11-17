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

def c2python(target):
    VcxProj(target).add_by_settings(py).write(target)

if __name__ == '__main__':
    c2python('C2Python\\C2Python.vcxproj')
