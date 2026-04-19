@echo off
clang src/ConsolMatrix.c -c -o obj/ConsolMatrix.obj
clang --shared src/ConsolMatrix.c -o bin/ConsolMatrix.dll -Wl,/IMPLIB:lib/ConsolMatrix.lib -DCOMPILING_DLL
llvm-lib /out:static/ConsolMatrix.lib obj/ConsolMatrix.obj
pause