#ifndef HITABLE
#define HITABLE

#include "ray.h"

struct hit_record {
    rtnum   t;
    vec3    p;
    vec3    normal;
};

class hitable {
public:
    virtual bool hit(const ray& r, rtnum t_min, rtnum t_max, hit_record& rec) const = 0;
};

#endif
