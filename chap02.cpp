#include <iostream>
#include "ray.h"

static const int MAX_COLOR_VAL = 255;
static const int SCREEN_W = 500;
static const int SCREEN_H = 300;


using namespace std;

static const rtnum COLOR_ROUND_MULT = rtnum(MAX_COLOR_VAL) + 0.99;
static inline int magicRound(rtnum r) {return COLOR_ROUND_MULT * r;}

static inline void outputPPMPixel(int r, int g, int b) {
	cout << r << " " << g << " " << b << " ";
}


static void outputPPMHeader(int imgWidth, int imgHeight, int maxColor) {
	cout << "P3" << endl;
	cout << imgWidth << " " << imgHeight << endl;
	cout << maxColor << endl;
}



vec3 color(const ray& r) {
	const vec3 WHITE_COLOR(1.0, 1.0, 1.0);
	const vec3 NICE_BLUE_COLOR(0.0, 0.2, 0.9);

	vec3 unit_dir = unit_vector(r.direction());
	rtnum t = 0.5 * (unit_dir.y() + 1.0);

	return (1.0 - t) * WHITE_COLOR + t * NICE_BLUE_COLOR;
}

int main() {

	int nx = SCREEN_W;
	int ny = SCREEN_H;

	outputPPMHeader(nx, ny, MAX_COLOR_VAL);

	vec3 ll_corner(-2.0, -1.0, -1.0);
	vec3 horizontal(4.0, 0.0, 0.0);
	vec3 vertical(0.0, 2.0, 0.0);
	vec3 origin(0.0, 0.0, 0.0);

	for( int j = ny - 1; j >= 0; j--) {
		// u v are the interpolation multipliers
		float v = float(j) / float(ny);

		for( int i = 0; i < nx; i++) {
			float u = float(i) / float(nx);

			ray r(origin, ll_corner + u * horizontal + v * vertical);
			vec3 col = color(r);
			int ir = magicRound(col[0]);
			int ig = magicRound(col[1]);
			int ib = magicRound(col[2]);

			outputPPMPixel(ir, ig, ib);
		}
		cout << endl;
	}

}
