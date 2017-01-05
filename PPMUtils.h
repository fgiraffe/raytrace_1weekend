#ifndef PPMUTILS_H
#define PPMUTILS_H

#include <iostream>

#include "vec3.h"

using namespace std;

const int MAX_COLOR_VAL = 255;

// functions for converting "world" colors (range 0.0 - 1.0) to
// PPM colors, int range 0 - MAX_COLOR_VAL
const rtnum COLOR_ROUND_MULT = rtnum(MAX_COLOR_VAL) + 0.99;
inline int PPM_PixelColor(rtnum r) {return COLOR_ROUND_MULT * r;}


inline void outputPPMPixel(int r, int g, int b) {
	cout << r << " " << g << " " << b << " ";
}


inline void outputPPMHeader(int imgWidth, int imgHeight, int maxColor) {
	cout << "P3" << endl;
	cout << imgWidth << " " << imgHeight << endl;
	cout << maxColor << endl;
}


#endif
