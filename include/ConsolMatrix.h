// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 RMT0
// ConsolMatr TRUE
// H FILE
// 1.0.1 version
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
typedef struct
{
	int x_size;
	int y_size;
	unsigned char* buffer;
} ConsolMatrix;
EXPORT bool ConsolMatrix_init(ConsolMatrix* matrix, int x, int y);
EXPORT bool ConsolMatrix_destroy(ConsolMatrix* matrix);
EXPORT bool ConsolMatrix_drawPixel(ConsolMatrix* matrix, int x, int y, unsigned char stateR, unsigned char stateG, unsigned char stateB); // function for drawing pixel
EXPORT bool ConsolMatrix_drawPixelA(ConsolMatrix* matrix, int buffer_address, unsigned char stateR, unsigned char stateG, unsigned char stateB); // function for drawing pixel
EXPORT bool ConsolMatrix_fillAll(ConsolMatrix* matrix, unsigned char state); // function for filling matrix
EXPORT bool ConsolMatrix_refreshMatrix(ConsolMatrix* matrix); // function for refreshing
#ifdef __cplusplus
}
#endif
#endif