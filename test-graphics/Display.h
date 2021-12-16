/*
 * Display.h
 *
 *  Created on: Dec 15, 2021
 *      Author: luke
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#define WIDTH 40
#define HEIGHT 40

class Display {
public:
	Display();
	virtual ~Display();
	void drawPixel(int x, int y, int value);
	void drawLine(int x1, int y1, int x2, int y2, int value);
	void drawRectangle(int x1, int y1, int x2, int y2, int value);
	void clear();
	void fill();
	void update();

private:
	//TODO: Make this dynamically allocated
	char buffer[WIDTH][HEIGHT];
};

#endif /* DISPLAY_H_ */
