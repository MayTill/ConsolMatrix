// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 RMT0
// ConsolMatrix
// H FILE
// 2.0.0pre version
#ifndef CMT
#define CMT
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>
#ifdef COMPILING_DLL
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif
EXPORT bool ConsolMatrix_init(int x, int y);
EXPORT bool ConsolMatrix_deinit();
EXPORT bool ConsolMatrix_drawPixel(int x, int y, unsigned char stateR, unsigned char stateG, unsigned char stateB); // function for drawing pixel
EXPORT bool ConsolMatrix_drawPixelA(int buffer_address, unsigned char stateR, unsigned char stateG, unsigned char stateB); // function for drawing pixel
EXPORT bool ConsolMatrix_fillAll(unsigned char state); // function for filling matrix
EXPORT bool ConsolMatrix_refreshMatrix(); // function for refreshing
#ifdef __cplusplus
}
#endif
#endif