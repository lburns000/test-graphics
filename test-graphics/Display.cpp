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

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

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
				lines[row] += " *";
			}
			else {
				lines[row] += "  ";
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
	// Constrain x
	if (x < 0) {x = 0;}
	if (x > WIDTH - 1) {x = WIDTH - 1;}
	// Constrain y
	if (y < 0) {y = 0;}
	if (y > HEIGHT - 1) {y = HEIGHT - 1;}

	buffer[x][y] = value;
}

void Display::drawLine(int x1, int y1, int x2, int y2, int value) {

	int x, y, dx, dy;

	// Constrain x1
	if (x1 < 0) {x1 = 0;}
	if (x1 > WIDTH - 1) {x1 = WIDTH - 1;}
	// Constrain y1
	if (y1 < 0) {y1 = 0;}
	if (y1 > HEIGHT - 1) {y1 = HEIGHT - 1;}
	// Constrain x2
	if (x2 < 0) {x2 = 0;}
	if (x2 > WIDTH - 1) {x2 = WIDTH - 1;}
	// Constrain y2
	if (y2 < 0) {y2 = 0;}
	if (y2 > HEIGHT - 1) {y2 = HEIGHT - 1;}

	// Make sure x1 <= x2
	if (x1 > x2) {
		swap (x1, x2);
		swap (y1, y2);
	}

	// Use Bresenham's Line Algorithm
	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;

	// If slope <= 1, find y values for each x
	if (dx >= dy) {
		int A = dy << 1; // Multiply dy by 2
		int B = dx << 1; // Multiply dx by 2
		int C = A - B;
		int P = A - dx;

		drawPixel(x, y, value); // Draw start pixel

		while (x < x2) {
			if (P < 0) {
				drawPixel(x+1, y, value);
				P += A;
			}
			else {
				drawPixel(x+1, y+1, value);
				y++;
				P += C;
			}

			x++;
		}
	}
	// If slope > 1, find x values for each y
	else {
		int A = dx << 1; // Multiply dx by 2
		int B = dy << 1; // Multiply dy by 2
		int C = A - B;
		int P = A - dy;

		drawPixel(x, y, value); // Draw start pixel

		while (y < y2) {
			if (P < 0) {
				drawPixel(x, y+1, value);
				P += A;
			}
			else {
				drawPixel(x+1, y+1, value);
				x++;
				P += C;
			}

			y++;
		}
	}
}

void Display::drawRectangle(int x1, int y1, int x2, int y2, int value) {

	drawLine(x1, y1, x2, y1, 1); // Draw the top
	drawLine(x1, y1, x1, y2, 1); // Draw the left side
	drawLine(x1, y2, x2, y2, 1); // Draw the bottom
	drawLine(x2, y1, x2, y2, 1); // Draw the right side
}

void Display::drawCircle(int xc, int yc, int r, int value) {
	// Constrain x
	if (xc < 0) {xc = 0;}
	if (xc > WIDTH - 1) {xc = WIDTH - 1;}
	// Constrain y
	if (yc < 0) {yc = 0;}
	if (yc > HEIGHT - 1) {yc = HEIGHT - 1;}

	// Use Bresenham's Circle Drawing Algorithm
	int P = 3 - (r << 1);
	int x = 0;
	int y = r;
	drawPixel(xc + x, yc + y, 1);
	drawPixel(xc + x, yc - y, 1);
	drawPixel(xc - x, yc + y, 1);
	drawPixel(xc - x, yc - y, 1);
	drawPixel(yc + y, xc + x, 1);
	drawPixel(yc + y, xc - x, 1);
	drawPixel(yc - y, xc + x, 1);
	drawPixel(yc - y, xc - x, 1);

	while (x <= y) {
		x++;
		if (P < 0) {
			drawPixel(xc + x, yc + y, 1);
			drawPixel(xc + x, yc - y, 1);
			drawPixel(xc - x, yc + y, 1);
			drawPixel(xc - x, yc - y, 1);
			drawPixel(yc + y, xc + x, 1);
			drawPixel(yc + y, xc - x, 1);
			drawPixel(yc - y, xc + x, 1);
			drawPixel(yc - y, xc - x, 1);

			P += ((x << 1) + 3);
		}
		else {
			y--;
			drawPixel(xc + x, yc + y, 1);
			drawPixel(xc + x, yc - y, 1);
			drawPixel(xc - x, yc + y, 1);
			drawPixel(xc - x, yc - y, 1);
			drawPixel(yc + y, xc + x, 1);
			drawPixel(yc + y, xc - x, 1);
			drawPixel(yc - y, xc + x, 1);
			drawPixel(yc - y, xc - x, 1);

			P += ((x - y) << 1) + 5;
		}
	}
}

