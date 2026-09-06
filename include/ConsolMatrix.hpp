// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 RMT0
// ConsolMatrix
// HPP FILE
// 2.0.0pre version
#ifndef CMTPP
#define CMTPP
#include "ConsolMatrix.h"
namespace ConsolMatrix
{
	inline static bool init(int x, int y) { return ConsolMatrix_init(x, y); };
	inline static bool deinit() { return ConsolMatrix_deinit(); };
	inline static bool drawPixel(int x, int y, unsigned char stateR, unsigned char stateG, unsigned char stateB) { return ConsolMatrix_drawPixel(x, y, stateR, stateG, stateB); };
	inline static bool drawPixelA(int buffer_address, unsigned char stateR, unsigned char stateG, unsigned char stateB) { return ConsolMatrix_drawPixelA(buffer_address, stateR, stateG, stateB); };
	inline static bool fillAll(unsigned char state) { return ConsolMatrix_fillAll(state); };
	inline static bool refreshMatrix() { return ConsolMatrix_refreshMatrix(); };
}
#endif
