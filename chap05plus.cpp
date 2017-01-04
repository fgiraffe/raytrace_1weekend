#include <iostream>
#include "sphere.h"
#include "hitable_list.h"
#include "float.h"

static const int MAX_COLOR_VAL = 255;
static const int SCREEN_W = 200;
static const int SCREEN_H = SCREEN_W / 2;

static const int NUM_OBJECTS = 2;

using namespace std;

// functions for converting "world" colors (range 0.0 - 1.0) to
// PPM colors, int range 0 - MAX_COLOR_VAL
static const rtnum COLOR_ROUND_MULT = rtnum(MAX_COLOR_VAL) + 0.99;
static inline int PPM_PixelColor(rtnum r) {return COLOR_ROUND_MULT * r;}


static inline void outputPPMPixel(int r, int g, int b) {
	cout << r << " " << g << " " << b << " ";
}


static void outputPPMHeader(int imgWidth, int imgHeight, int maxColor) {
	cout << "P3" << endl;
	cout << imgWidth << " " << imgHeight << endl;
	cout << maxColor << endl;
}

inline vec3 backgroundColor(const ray& r) {
	// simple function which creates a blue to white gradient background
	const vec3 WHITE_COLOR(1.0, 1.0, 1.0);
	const vec3 NICE_BLUE_COLOR(0.0, 0.2, 0.9);
	vec3 unit_dir = unit_vector(r.direction());
	rtnum t = 0.5 * (unit_dir.y() + 1.0);

// 	blended_value = (1-t)* start_value + t* end_value,
	return (1.0 - t) * WHITE_COLOR + (t * NICE_BLUE_COLOR);
}


static vec3 color(const ray& r, hitable *world) {

    hit_record rec;

    if (world->hit(r, 0.0, MAXFLOAT, rec)) {
        return 0.5 * vec3(rec.normal.x() + 1,
                          rec.normal.y() + 1,
                          rec.normal.z() + 1);
    } else {
        return backgroundColor(r);
    }

}


int main() {

	int nx = SCREEN_W;
	int ny = SCREEN_H;

	outputPPMHeader(nx, ny, MAX_COLOR_VAL);

	vec3 ll_corner(-2.0, -1.0, -1.0);
	vec3 horizontal(4.0, 0.0, 0.0);
	vec3 vertical(0.0, 2.0, 0.0);
	vec3 origin(0.0, 0.0, 0.0);

    hitable *objectList[NUM_OBJECTS];
    objectList[0] = new sphere(vec3(0, 0, -1), 0.5);
    objectList[1] = new sphere(vec3(0, -100.5, -1), 100);

    hitable *world = new hitable_list(objectList, NUM_OBJECTS);

	for( int j = ny - 1; j >= 0; j--) {
		// u v are the interpolation multipliers
		float v = float(j) / float(ny);

		for( int i = 0; i < nx; i++) {
			float u = float(i) / float(nx);

			ray r(origin, ll_corner + u * horizontal + v * vertical);
			vec3 col = color(r, world);
			int ir = PPM_PixelColor(col[0]);
			int ig = PPM_PixelColor(col[1]);
			int ib = PPM_PixelColor(col[2]);

			outputPPMPixel(ir, ig, ib);
		}
		cout << endl;
	}

}
