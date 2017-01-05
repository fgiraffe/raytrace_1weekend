#include <iostream>
#include "float.h"

#include "sphere.h"
#include "hitable_list.h"
#include "camera.h"
#include "PPMUtils.h"

static const int SCREEN_W = 500;
static const int SCREEN_H = SCREEN_W / 2;

static const int NUM_OBJECTS = 2;

using namespace std;


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
    int ns = 10;

	outputPPMHeader(nx, ny, MAX_COLOR_VAL);

    camera cam;
    hitable *objectList[NUM_OBJECTS];
    objectList[0] = new sphere(vec3(0, 0, -1), 0.5);
    objectList[1] = new sphere(vec3(0, -100.5, -1), 100);

    hitable *world = new hitable_list(objectList, NUM_OBJECTS);

	for( int j = ny - 1; j >= 0; j--) {
		for( int i = 0; i < nx; i++) {
            vec3 col(0,0,0);

            for (size_t s   = 0; s < ns; s++) {
                float u = float(i + drand48()) / float(nx);
                float v = float(j + drand48()) / float(ny);

    			ray r = cam.get_ray(u,v);
    			col += color(r, world);
            }

            col /= float(ns);
			int ir = PPM_PixelColor(col[0]);
			int ig = PPM_PixelColor(col[1]);
			int ib = PPM_PixelColor(col[2]);

			outputPPMPixel(ir, ig, ib);
		}
		cout << endl;
	}

}
