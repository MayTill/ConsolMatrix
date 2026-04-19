// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 RMT0
// ConsolMatr TRUE
// HPP FILE
// 1.0.1 version
#ifndef CMTPP
#define CMTPP
#include "ConsolMatrix.h"
class ConsolMatrix_class
{
	ConsolMatrix obj[1];
	public:
	bool init_result;
	ConsolMatrix_class(int x, int y)
	{
		init_result = ConsolMatrix_init(obj, x, y);
	}
	~ConsolMatrix_class()
	{
		ConsolMatrix_destroy(obj);
	}
	bool drawPixel(int x, int y, unsigned char stateR, unsigned char stateG, unsigned char stateB)
	{
		return ConsolMatrix_drawPixel(obj, x, y, stateR, stateG, stateB);
	}
	bool drawPixelA(int buffer_address, unsigned char stateR, unsigned char stateG, unsigned char stateB)
	{
		return ConsolMatrix_drawPixelA(obj, buffer_address, stateR, stateG, stateB);
	}
	bool fillAll(unsigned char state)
	{
		return ConsolMatrix_fillAll(obj, state);
	}
	bool refreshMatrix()
	{
		return ConsolMatrix_refreshMatrix(obj);
	}
};
#endif
