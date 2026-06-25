@echo off
if not exist "bin" mkdir bin
if not exist "obj" mkdir obj
clang src\ConsolMatrix.c -c -o obj\ConsolMatrix.obj -Iinclude
clang --shared src\ConsolMatrix.c -o bin\ConsolMatrix.dll -Wl,/IMPLIB:bin\ConsolMatrix.lib -DCOMPILING_DLL
llvm-lib /out:bin\ConsolMatrix_static.lib obj\ConsolMatrix.obj
del /Q obj\*
rmdir obj
pause