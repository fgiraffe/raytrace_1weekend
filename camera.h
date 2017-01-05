#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"

class camera {
public:
    camera() {
        ll_corner = vec3(-2.0, -1.0, -1.0);
        origin = vec3(0, 0, 0);

        horizontal = vec3(4.0, 0, 0);
        vertical = vec3(0, 2.0, 0);
    }

    ray get_ray(rtnum u, rtnum v) {
        return ray(origin, ll_corner + u*horizontal + v*vertical - origin);
    }

    vec3 origin;
    vec3 ll_corner;

	vec3 horizontal;
	vec3 vertical;

};

#endif
