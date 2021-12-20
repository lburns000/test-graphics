/*
 * test-graphics
 */

#include <iostream>
#include <string>
#include "Display.h"

using namespace std;

int main() {
	Display myDisp;
	myDisp.drawPixel(0, 0, 1);
	myDisp.drawPixel(7, 7, 1);
	myDisp.drawPixel(0, 7, 1);
	myDisp.drawPixel(7, 0, 1);
	myDisp.update();

	myDisp.drawRectangle(0,0,7,7,1);
	myDisp.drawRectangle(2,2,5,5,1);
	myDisp.update();

	myDisp.clear();
	myDisp.update();

	myDisp.fill();
	myDisp.update();

	int x1, y1, r;
	myDisp.clear();
	cout << "Enter x1 y1 r: ";
	cin >> x1 >> y1 >> r;
	myDisp.drawCircle(x1,y1,r,1);
	myDisp.update();

	return 0;
}
