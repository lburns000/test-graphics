/*
 * Display.cpp
 *
 *  Created on: Dec 15, 2021
 *      Author: luke
 */

#include "Display.h"
#include <iostream>
#include <string>
#include <cmath>

Display::Display() {
	//Initialize screen
	clear();
}

Display::~Display() {

}

void Display::clear() {
	for (int col = 0; col < WIDTH; col++) {
			for (int row = 0; row < HEIGHT; row++) {
				buffer[col][row] = 0;
			}
		}
}

void Display::fill() {
	for (int col = 0; col < WIDTH; col++) {
			for (int row = 0; row < HEIGHT; row++) {
				buffer[col][row] = 1;
			}
		}
}

void Display::update() {
	std::string lines[HEIGHT];

	for (int row = 0; row < HEIGHT; row++) {
		for (int col = 0; col < WIDTH; col++) {
			if (buffer[col][row] == 1) {
				lines[row] += " * ";
			}
			else {
				lines[row] += "   ";
			}
		}
	}
	for (int line = 0; line < HEIGHT; line++) {
		std::cout << lines[line] << std::endl;
	}
	std::cout << std::endl;
}

void Display::drawPixel(int x, int y, int value)
{
	buffer[x][y] = value;
}

void Display::drawLine(int x1, int y1, int x2, int y2, int value) {

	//TODO: Use Bresenham's Algorithm to make this cheaper

	int dx = x2 - x1;
	int dy = y2 - y1;
	double m = static_cast<double>(dy) / static_cast<double>(dx);

	drawPixel(x1, y1, value);	// Draw start pixel

	int x = x1 + 1;

	while (x <= x2) {
		double yd = round(m * (x - x1) + y1);
		int y = yd;
		drawPixel(x, yd, 1);
		std::cout << "At x = " << x << ", y calculated to be: " << y << std::endl;
		std::cout << "Drawing pixel at: (" << x << ", " << y << ")\n\n";
		x++;
	}
}

void Display::drawRectangle(int x1, int y1, int x2, int y2, int value) {
	int colDiff = x2 - x1;
	int rowDiff = y2 - y1;

	for (int row = 0; row < HEIGHT; row++) {
		for (int col = 0; col < WIDTH; col++) {

			// Draw the top and bottom
			if ((y1 == row) || (y2 == row)) {
				for (int i = x1; i <= x2; i++) {
					buffer[row][i] = value;
				}
			}

			// Draw the sides
			if (y1 < row && y2 > row) {
				buffer[row][x1] = value;
				buffer[row][x2] = value;
			}
		}
	}
}

