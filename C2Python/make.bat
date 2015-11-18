set VS=C:\Program Files (x86)\Microsoft Visual Studio 14.0
set PyX64=C:\Program Files\Python 3.5
set PyX32=C:\Program Files (x86)\Python 3.5
set PyLib=python35.lib
set C2Python=my_python

call "%VS%\VC\vcvarsall.bat" amd64
cl %C2Python%.c /I"%PyX64%\include" "%PyX64%\libs\%PyLib%" /Fe%C2Python%_x64.exe
%C2Python%_x64

call "%VS%\VC\vcvarsall.bat"
cl %C2Python%.c /I"%PyX32%\include" "%PyX32%\libs\%PyLib%" /Fe%C2Python%_x32.exe
%C2Python%_x32
