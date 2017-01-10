#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_


#include "hitable.h"

class triangle: public hitable {
public:
    triangle() {};

    triangle(const vec3& p0, const vec3& p1, const vec3& p2, const vec3& color);

    virtual bool hit(const ray& r, rtnum t_min, rtnum t_max, hit_record& rec) const;

    vec3    _p0;
    vec3    _p1;
    vec3    _p2;

    vec3    _color;


};

#endif
