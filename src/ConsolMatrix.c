// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 RMT0
// ConsolMatrix
// 2.1.0pre version
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ConsolMatrix.h>
int x_size = 0;
int y_size = 0;
unsigned char* buffer = NULL;
unsigned char* buffer2 = NULL;
int drawn = 0;
bool ConsolMatrix_init(int x, int y)
{
	if (buffer) return false;
	if (buffer2) return false;
	if (x <= 0) return false;
	if (y <= 0) return false;
	if ((long long)x * (long long)y  > INT_MAX) return false; // so the second doesn't overflow
	if ((long long)x * (long long)y * 3 > INT_MAX) return false;
	x_size = x;
	y_size = y;
	buffer = calloc(1, x * y * 3);
	buffer2 = calloc(1, x * y * 3);
	if (!buffer || !buffer2)
	{
		free(buffer);
		free(buffer2);
		buffer = NULL;
		buffer2 = NULL;
		return false;
	}
	#ifdef _WIN32
	system("chcp 65001");
	#endif
	drawn = 0;
	ConsolMatrix_refreshMatrixAndFix();
	return true;
}
bool ConsolMatrix_deinit()
{
	if (!buffer) return false;
	if (!buffer2) return false;
	free(buffer); // freeing a buffers
	free(buffer2);
	buffer = NULL;
	buffer2 = NULL;
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
	if (!buffer2) return false;
	// loop for refreshing
	fputs("\033[H", stdout);
	fputs("\033[0m", stdout);
	for (int i = 0; i < x_size * y_size; i++)
	{
		if (i >= drawn * x_size && i < (drawn + (y_size >= 10 ? y_size / 10 : 1)) * x_size)
		{
			printf("\033[%d;%dH", (i / x_size) + 1, (i % x_size) * 2 + 1);
			colorForeground(buffer[i * 3], buffer[i * 3 + 1], buffer[i * 3 + 2]);
			fputs("\u2588\u2588", stdout);
			fputs("\033[0m", stdout);
			continue;
		}
		if (!memcmp(buffer + (i * 3), buffer2 + (i * 3), 3)) continue;
		printf("\033[%d;%dH", (i / x_size) + 1, (i % x_size) * 2 + 1);
		colorForeground(buffer[i * 3], buffer[i * 3 + 1], buffer[i * 3 + 2]);
		fputs("\u2588\u2588", stdout);
		fputs("\033[0m", stdout);
	}
	memcpy(buffer2, buffer, x_size * y_size * 3);
	if (y_size >= 10) drawn += y_size / 10;
	else drawn++;
	if (drawn >= y_size) drawn = 0;
	fflush(stdout);
	return true; // return OK
}
bool ConsolMatrix_refreshMatrixAndFix() // function for refreshing and fixing
{
	if (!buffer) return false;
	if (!buffer2) return false;
	// loop for refreshing
	fputs("\033[H", stdout);
	fputs("\033[0m", stdout);
	for (int i = 0; i < x_size * y_size; i++)
	{
		if (!(i % x_size) && i) printf("\n");
		colorForeground(buffer[i * 3], buffer[i * 3 + 1], buffer[i * 3 + 2]);
		fputs("\u2588\u2588", stdout);
		fputs("\033[0m", stdout);
	}
	memcpy(buffer2, buffer, x_size * y_size * 3);
	fflush(stdout);
	return true; // return OK
}