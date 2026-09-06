// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 RMT0
// ConsolMatrix
// 2.0.0pre version
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ConsolMatrix.h>
int x_size = 0;
int y_size = 0;
unsigned char* buffer = NULL;
bool ConsolMatrix_init(int x, int y)
{
	if (buffer) return false;
	if (x <= 0) return false;
	if (y <= 0) return false;
	x_size = x;
	y_size = y;
	buffer = calloc(1, x * y * 3);
	#ifdef _WIN32
	system("chcp 65001");
	#endif
	if (!buffer) return false;
	return true;
}
bool ConsolMatrix_deinit()
{
	if (!buffer) return false;
	free(buffer); // freeing a buffer
	buffer = NULL;
	return true; // return OK
}
bool ConsolMatrix_drawPixel(int x, int y, unsigned char stateR, unsigned char stateG, unsigned char stateB) // function for drawing pixel
{
	if (!buffer) return false;
	// x & y checking
	if (x >= x_size) return false;
	if (y >= y_size) return false;
	if (x < 0) return false;
	if (y < 0) return false;
	// writing into a buffer
	int buffer_address = (x_size * y + x);
	buffer[buffer_address * 3] = stateR;
	buffer[buffer_address * 3 + 1] = stateG;
	buffer[buffer_address * 3 + 2] = stateB;
	return true; // return OK
}
bool ConsolMatrix_drawPixelA(int buffer_address, unsigned char stateR, unsigned char stateG, unsigned char stateB) // function for drawing pixel
{
	if (!buffer) return false;
	// buffer_addres checking
	if (buffer_address >= (x_size * y_size)) return false;
	if (buffer_address < 0) return false;
	// writing into a buffer
	buffer[buffer_address * 3] = stateR;
	buffer[buffer_address * 3 + 1] = stateG;
	buffer[buffer_address * 3 + 2] = stateB;
	return true; // return OK
}
bool ConsolMatrix_fillAll(unsigned char state) // function for filling matrix
{
	if (!buffer) return false;
	// filling matrix
	memset(buffer, state, x_size * y_size * 3);
	return true; // return OK
}
void colorForeground(unsigned char valueR, unsigned char valueG, unsigned char valueB) // function for coloring foreground
{
    printf("\033[38;2;%d;%d;%dm", valueR, valueG, valueB);
}
bool ConsolMatrix_refreshMatrix() // function for refreshing
{
	if (!buffer) return false;
	// clearing screen
	fputs("\033[H", stdout);
	fputs("\033[0m", stdout);
	// loop for refreshing
	for (int y = 0; y < y_size; y++)
	{
		for (int x = 0; x < x_size; x++)
		{
			int buffer_address = x_size * y + x;
			colorForeground(buffer[buffer_address * 3], buffer[buffer_address * 3 + 1], buffer[buffer_address * 3 + 2]);
			fputs("\u2588\u2588",stdout);
		}
		fputs("\033[0m\n", stdout);
	}
	return true; // return OK
}
