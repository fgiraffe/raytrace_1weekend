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

static vec3 random_in_unit_sphere() {
	vec3 p;
	do {
		p = 2.0 * vec3(drand48(), drand48(), drand48()) - vec3(1, 1, 1);
	} while(p.squared_length() >= 1.0);
	return p;
}

static vec3 color(const ray& r, hitable *world) {

    hit_record rec;

    if (world->hit(r, 0.001, MAXFLOAT, rec)) {
		vec3 target = rec.p + rec.normal + random_in_unit_sphere();
		return 0.5 * color(ray(rec.p, target - rec.p), world);
    } else {
		vec3 unit_direction = unit_vector(r.direction());
		float t = 0.5 * (unit_direction.y() + 1.0);
		return (1.0 - t) * vec3(1.0,1.0,1.0) + t * vec3(0.5, 0.7, 1.0);
    }

}


static vec3 color_ch5(const ray& r, hitable *world) {

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
    int ns = 20;

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
			// adjust to "gamma 2" to power 1/2 which is sqrt
			// col = vec3( sqrt(col[0]), sqrt(col[1]), sqrt(col[2]) );
			int ir = PPM_PixelColor(col[0]);
			int ig = PPM_PixelColor(col[1]);
			int ib = PPM_PixelColor(col[2]);

			outputPPMPixel(ir, ig, ib);
		}
		cout << endl;
	}

}
