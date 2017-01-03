#include <iostream>

#include "vec3.h"

static const int MAX_COLOR_VAL = 255;

static const int CANVAS_W = 200;
static const int CANVAS_H = 100;

static const float ROUND_TO_INT  = float (MAX_COLOR_VAL) + 0.99;

using namespace std;

static void outputPPMHeader(int imgWidth, int imgHeight, int maxColor) {
	cout << "P3" << endl;
	cout << imgWidth << " " << imgHeight << endl;
	cout << maxColor << endl;
}


int main(int argc, char *argv[]) {

	int nx = CANVAS_W;
	int ny = CANVAS_H;
	
	outputPPMHeader(nx, ny, MAX_COLOR_VAL);

	for (int j = ny - 1; j >= 0; j--) {
		for (int i = 0; i < nx; i++) {
			float r = float(i) / float(nx);
			float g = float(j) / float(ny);
			float b = 0.2;
			
			int ir = int(ROUND_TO_INT * r);
			int ig = int(ROUND_TO_INT * g);
			int ib = int(ROUND_TO_INT * b);
			
			cout << ir << " " << ig << " " << ib << endl;
		}
		
	}	
}