#ifndef SPHERE
#define SPHERE

#include "hitable.h"

class sphere: public hitable {
public:
    sphere() {};
    sphere(vec3 cen, rtnum r) : center(cen), radius(r) {};

    virtual bool hit(const ray& r, rtnum t_min, rtnum t_max, hit_record& rec) const;

    vec3    center;
    rtnum   radius;
};

bool sphere::hit(const ray& r, rtnum t_min, rtnum t_max, hit_record& rec) const {
    vec3 oc = r.origin() - center;
	rtnum a = dot(r.direction(), r.direction());
	rtnum b = dot(oc, r.direction());
	rtnum c = dot(oc, oc) - radius * radius;
	rtnum discriminant = b*b - a*c;

    if (discriminant > 0) {
        rtnum temp = (-b - sqrt(discriminant)) / a;

        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            return true;
        }

        temp = (-b + sqrt(discriminant)) / a;
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            return true;
        }
	}

    return false;
}




#endif // SPHERE
