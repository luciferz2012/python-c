set VS=C:\Program Files (x86)\Microsoft Visual Studio 14.0
set PyX64=C:\Program Files\Python 3.5
set PyX32=C:\Program Files (x86)\Python 3.5
set PyLib=python35.lib
set C2Python=ifc

copy /y ifcengine\include\ifcengine.h ifcengine.h
copy /y ifcengine\data\* *

swig -python ifc.i

call "%VS%\VC\vcvarsall.bat" amd64
cl %C2Python%_wrap.c /I"%PyX64%\include" "%PyX64%\libs\%PyLib%" ifcengine\lib64\ifcengine.lib /Fe_%C2Python%.pyd /LD /D "_WINDOWS"
copy /y ifcengine\bin64\ifcengine.dll ifcengine.dll
"%PyX64%\python.exe" runme.py

call "%VS%\VC\vcvarsall.bat"
cl %C2Python%_wrap.c /I"%PyX32%\include" "%PyX32%\libs\%PyLib%" ifcengine\lib32\ifcengine.lib /Fe_%C2Python%.pyd /LD /D "_WINDOWS"
copy /y ifcengine\bin32\ifcengine.dll ifcengine.dll
"%PyX32%\python.exe" runme.py
