#include <iostream>
#include <math.h>
#include "graphics.h"

#define NUMBEROFITERATIONS 30
#define CE -1
unsigned long long cntit = 0;
unsigned long long cnttot = 0;
long long cntpixel;
using namespace std;
int w1, w2;
double pythagoras(double x1, double y1, double x2, double y2) {
	if (x2 < y2) {
		swap(x2, y2);
	}
	if (y2 > y1) {
		swap(y2, y1);
	}
	return sqrt((x2 - x1) * (x2 - x1) + (y1 - y2) * (y1 - y2));
}
bool inthecircle(double r, double i) {
	if (pythagoras(500, 500, r, i) <= 400) {
		return true;
	}
	return false;
}
bool inthecircle2(double r, double i) {
	if (pythagoras(0, 0, r, i) <= 2) {
		return true;
	}
	return false;
}
void iteratethefunction(double r, double i, double& real, double& imaginary) {
	imaginary = 2 * r * i;
	real = r * r - i * i+CE;
	//(real+imaginary i)^2+real+imaginary i
	//real^2+ 2 xreal x imaginary i - imaginary x imaginary +real + imaginary
}
void welcome() {
	cout << "WELCOME TO FRACTOBROT" << endl;
	cout << "Here, you can eperience the behavior of Julia sets and the Mandelbrot set";
	cout << endl << "<----------ITERATING---------->";
}
void showresults() {
	cout << "CURRENT ITERATION: " << cntit << endl;
	cout << "PIXELS FILLED AT CURRENT ITERATION: " << cntpixel << endl;
	cout << "TOTAL FILLED PIXELS (RED/YELLOW): " << cnttot << endl;
	delay(2000);
}
void drawthesecondwindow() {
	setcurrentwindow(w2);
	setcurrentwindow(w1);
}
double real, imaginar;
bool ver=0;

int main() {
	int w2 = initwindow(1000, 1000, "MandelbrotZoomed");
	int w1 = initwindow(1000, 1000, "MandelbrotWindow");
	setcurrentwindow(w1);
	setcolor(YELLOW);
	line(0, 500, 1000, 500);
	line(500, 0, 500, 1000);
	circle(500, 500, 400); //CENTER IN 400
	double pivot = 400;
	setcolor(WHITE);
	welcome();
	for (unsigned int k = 1; k <= NUMBEROFITERATIONS; k++) {
		setcurrentwindow(w1);
		cntit++;
		cntpixel = 0;
		for (double i = 100; i <= 900; i++) {
			ver = 0;
			for (double j = 100; j <= 900; j++) {
				if (getpixel(j, i) == BLACK) {
					if (inthecircle(j, i)) {
						//putpixel(j, i, RED);
						double real = (j - 500) / 200, realfin;
						double imaginary = (i - 500) / 200, imgfin;
						//cout << real << imaginary << endl;
						for (unsigned int l = 1; l <= k; l++) {
							iteratethefunction(real, imaginary, realfin, imgfin);
							//cout << realfin << imgfin <<endl;
							if (!inthecircle2(realfin, imgfin)) {
								if (l % 2 == 1) {
									if (i >= 500 && j <= 500) {
										setcurrentwindow(w2);
										putpixel(j*2, (i-500)*2, GREEN);
										setcurrentwindow(w1);
									}
									cntpixel++;
									cnttot++;
									putpixel(j, i, GREEN);
									if (j&&ver==0) {
										ver = 1;
										cout << "ALPHA VALUE AT EPICENTRE: " << real << imaginary << " i" << endl;
									}
								}
								else {
									putpixel(j, i, BLUE);
									if (i >= 500 && j <= 500) {
										setcurrentwindow(w2);
										putpixel(j*2, (i-500)*2, BLUE);
										setcurrentwindow(w1);
									}
									cntpixel++;
									cnttot++;
									if (j&&ver==0) {
										ver = 1;
										cout << "ALPHA VALUE AT EPICENTRE: " << real << imaginary << " i" << endl;
									}
								}

							}
							real = realfin;
							imaginary = imgfin;
						}
					}
				}
			}
		}
		showresults();
	}
	iteratethefunction(1, 1, real, imaginar);
	cout << real << " " << imaginar;
	getch();
	return 0;
}


