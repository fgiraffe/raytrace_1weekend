#ifndef RAYH
#define RAYH

#include "vec3.h"

class ray
{
	public:
		ray() {}
		ray(const vec3& a, const vec3& b) {
			_A = a;
			_B = b;
		}

		vec3 origin() const {return _A;}
		vec3 direction() const {return _B;}

		vec3 point_at_parameter(rtnum t) const {return _B + t * _B;}
	
	private:
		vec3 _A;
		vec3 _B;
};


#endif
