// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 RMT0
// ConsolMatr TRUE
// 1.0.0 version
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ConsolMatrix.h"
bool ConsolMatrix_init(ConsolMatrix* matrix, int x, int y)
{
	if (!matrix) return false;
	if (x <= 0) return false;
	if (y <= 0) return false;
	matrix->x_size = x;
	matrix->y_size = y;
	matrix->buffer = calloc(1, x * y * 3);
	if (!matrix->buffer) return false;
	return true;
}
bool ConsolMatrix_destroy(ConsolMatrix* matrix)
{
	// matrix checking
	if (!matrix) return false;
	if (!matrix->buffer) return false;
	free(matrix->buffer); // freeing a buffer
	return true; // return OK
}
bool ConsolMatrix_drawPixel(ConsolMatrix* matrix, int x, int y, unsigned char stateR, unsigned char stateG, unsigned char stateB) // function for drawing pixel
{
	// matrix checking
	if (!matrix) return false;
	if (!matrix->buffer) return false;
	// x & y checking
	if (x >= matrix->x_size) return false;
	if (y >= matrix->y_size) return false;
	if (x < 0) return false;
	if (y < 0) return false;
	// writing into a buffer
	int buffer_address = (matrix->x_size * y + x);
	matrix->buffer[buffer_address * 3] = stateR;
	matrix->buffer[buffer_address * 3 + 1] = stateG;
	matrix->buffer[buffer_address * 3 + 2] = stateB;
	return true; // return OK
}
bool ConsolMatrix_drawPixelA(ConsolMatrix* matrix, int buffer_address, unsigned char stateR, unsigned char stateG, unsigned char stateB) // function for drawing pixel
{
	// matrix checking
	if (!matrix) return false;
	if (!matrix->buffer) return false;
	// buffer_addres checking
	if (buffer_address >= (matrix->x_size * matrix->y_size)) return false;
	if (buffer_address < 0) return false;
	// writing into a buffer
	matrix->buffer[buffer_address * 3] = stateR;
	matrix->buffer[buffer_address * 3 + 1] = stateG;
	matrix->buffer[buffer_address * 3 + 2] = stateB;
	return true; // return OK
}
bool ConsolMatrix_fillAll(ConsolMatrix* matrix, unsigned char state) // function for filling matrix
{
	// matrix checking
	if (!matrix) return false;
	if (!matrix->buffer) return false;
	// filling matrix
	memset(matrix->buffer, state, matrix->x_size * matrix->y_size * 3);
	return true; // return OK
}
void colorForeground(unsigned char valueR, unsigned char valueG, unsigned char valueB) // function for coloring foreground
{
    printf("\033[38;2;%d;%d;%dm", valueR, valueG, valueB);
}
bool ConsolMatrix_refreshMatrix(ConsolMatrix* matrix) // function for refreshing
{
	if (!matrix) return false;
	if (!matrix->buffer) return false;
	// clearing screen
	fputs("\033[H", stdout);
	fputs("\033[0m", stdout);
	// loop for refreshing
	for (int y = 0; y < matrix->y_size; y++)
	{
		for (int x = 0; x < matrix->x_size; x++)
		{
			int buffer_address = matrix->x_size * y + x;
			colorForeground(matrix->buffer[buffer_address * 3], matrix->buffer[buffer_address * 3 + 1], matrix->buffer[buffer_address * 3 + 2]);
			puts("лл");
		}
		fputs("\033[0m\n", stdout);
	}
	return true; // return OK
}
