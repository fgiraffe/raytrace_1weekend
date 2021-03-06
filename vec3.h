#ifndef VEC3
#define VEC3

#include <math.h>
#include <stdlib.h>
#include <iostream>

typedef float rtnum;

class vec3 {
	public:
		vec3() {}

		vec3(rtnum e0, rtnum e1, rtnum e2) {
			e[0] = e0; e[1] = e1; e[2] = e2;
			}

		inline rtnum x() const { return e[0]; }
		inline rtnum y() const { return e[1]; }
		inline rtnum z() const { return e[2]; }

		inline rtnum r() const { return e[0]; }
		inline rtnum g() const { return e[1]; }
		inline rtnum b() const { return e[2]; }

		// WTF does this operator do?
		inline const vec3& operator+() const {return *this;}
		inline vec3 operator-() const{return vec3(-e[0], -e[1], -e[2]); }

		inline rtnum operator[](int i) const {return e[i];}
		inline rtnum& operator[](int i) {return e[i];}

		inline vec3& operator+=(const vec3 &v2);
		inline vec3& operator-=(const vec3 &v2);
		inline vec3& operator*=(const vec3 &v2);
		inline vec3& operator/=(const vec3 &v2);

		inline vec3& operator*=(const rtnum t);
		inline vec3& operator/=(const rtnum t);

		inline rtnum length() const {
			return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
		}

		inline rtnum squared_length() const {
			return ((e[0]*e[0] + e[1]*e[1] + e[2]*e[2]));
		}

		inline void make_unit_vector();

		rtnum e[3];
};


inline std::istream& operator>>(std::istream &is, vec3 &t) {
	is >> t.e[0] >> t.e[1] >> t.e[2];
	return is;
}

inline std::ostream& operator<<(std::ostream &os, const vec3 &t) {
	os << t.e[0] << " " << t.e[1] << " " << t.e[2];
	return os;
}

inline void vec3::make_unit_vector() {
	rtnum k = 1.0 / sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
}

inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
	return vec3(v1.e[0] + v2.e[0],
			    v1.e[1] + v2.e[1],
				v1.e[2] + v2.e[2]);
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
	return vec3(v1.e[0] - v2.e[0],
			    v1.e[1] - v2.e[1],
				v1.e[2] - v2.e[2]);
}


inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
	return vec3(v1.e[0] * v2.e[0],
			    v1.e[1] * v2.e[1],
				v1.e[2] * v2.e[2]);
}


inline vec3 operator/(const vec3 &v1, const vec3 &v2) {
	return vec3(v1.e[0] / v2.e[0],
			    v1.e[1] / v2.e[1],
				v1.e[2] / v2.e[2]);
}

inline vec3 operator*(rtnum t, const vec3 &v) {
	return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator*(const vec3 &v, rtnum t) {
	return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator/(const vec3 &v, rtnum t) {
	return vec3(v.e[0]/t, v.e[1]/t, v.e[2]/t);
}

inline rtnum dot(const vec3 &v1, const vec3 &v2) {
	return (v1.e[0] * v2.e[0] +
			v1.e[1] * v2.e[1] +
			v1.e[2] * v2.e[2]);
}

inline vec3 cross(const vec3 &v1, const vec3 &v2) {
	return vec3(    (v1.e[1] * v2.e[2]) - (v1.e[2] * v2.e[1]),
				 ( -((v1.e[0] * v2.e[2]) - (v1.e[2] * v2.e[0]))),
				 (  (v1.e[0] * v2.e[1]) - (v1.e[1] * v2.e[0])) );
}

inline vec3& vec3::operator+=(const vec3 &v) {
	this->e[0] += v.e[0];
	this->e[1] += v.e[1];
	this->e[2] += v.e[2];
	return *this;
}

inline vec3& vec3::operator/=(const vec3 &v) {
	this->e[0] /= v.e[0];
	this->e[1] /= v.e[1];
	this->e[2] /= v.e[2];
	return *this;
}

inline vec3& vec3::operator/=(const rtnum t) {
	rtnum k = 1.0/t;
	this->e[0] *= k;
	this->e[1] *= k;
	this->e[2] *= k;
	return *this;
}

inline vec3 unit_vector(vec3 v) {
	return v / v.length();
}


#endif // VEC3
