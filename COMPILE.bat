@echo off
if not exist "bin" mkdir bin
if not exist "obj" mkdir obj
clang -Iinclude src\ConsolMatrix.c -c -o obj\ConsolMatrix.obj
clang -Iinclude --shared src\ConsolMatrix.c -o bin\ConsolMatrix.dll -Wl,/IMPLIB:bin\ConsolMatrix.lib -DCOMPILING_DLL
llvm-lib /out:bin\ConsolMatrix_static.lib obj\ConsolMatrix.obj
del /Q obj\*
rmdir obj
pause