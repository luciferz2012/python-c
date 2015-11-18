set VS=C:\Program Files (x86)\Microsoft Visual Studio 14.0
set PyX64=C:\Program Files\Python 3.5
set PyX32=C:\Program Files (x86)\Python 3.5
set PyLib=python35.lib
set Python2C=great_module

call "%VS%\VC\vcvarsall.bat" amd64
cl %Python2C%.c /I"%PyX64%\include" "%PyX64%\libs\%PyLib%" /Fe%Python2C%.pyd /LD
"%PyX64%\python.exe" runme.py

call "%VS%\VC\vcvarsall.bat"
cl %Python2C%.c /I"%PyX32%\include" "%PyX32%\libs\%PyLib%" /Fe%Python2C%.pyd /LD
"%PyX32%\python.exe" runme.py
