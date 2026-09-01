@echo off
if not exist "bin" mkdir bin
if not exist "obj" mkdir obj
clang -Iinclude src\ConsolMatrix.c -c -o obj\ConsolMatrix.obj
clang -Iinclude --shared src\ConsolMatrix.c -o bin\ConsolMatrix.dll -Wl,/IMPLIB:bin\ConsolMatrix.lib -DCOMPILING_DLL
llvm-lib /out:bin\ConsolMatrix_static.lib obj\ConsolMatrix.obj



clang -Iinclude src\ConsolMatrix.c -c -o obj\ConsolMatrix32.obj -m32
clang -Iinclude --shared src\ConsolMatrix.c -o bin\ConsolMatrix32.dll -Wl,/IMPLIB:bin\ConsolMatrix32.lib -DCOMPILING_DLL -m32
llvm-lib /out:bin\ConsolMatrix32_static.lib obj\ConsolMatrix32.obj
del /Q obj\*
rmdir obj
pause