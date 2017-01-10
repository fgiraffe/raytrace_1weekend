#include "triangle.h"

triangle::triangle(const vec3& p0, const vec3& p1, const vec3& p2, const vec3& color) :
        _p0(p0), _p1(p1), _p2(p2), _color(color) {
};


bool triangle::hit(const ray& r, rtnum t_min, rtnum t_max, hit_record& rec) const
{

        rtnum tval;
        rtnum A = _p0.x() - _p1.x();
        rtnum B = _p0.y() - _p1.y();
        rtnum C = _p0.z() - _p1.z();

        rtnum D = _p0.x() - _p2.x();
        rtnum E = _p0.y() - _p2.y();
        rtnum F = _p0.z() - _p2.z();

        rtnum G = r.direction().x();
        rtnum H = r.direction().y();
        rtnum I = r.direction().z();

        rtnum J = _p0.x() - r.origin().x();
        rtnum K = _p0.y() - r.origin().y();
        rtnum L = _p0.z() - r.origin().z();

        rtnum EIHF = E*I - H*F;
        rtnum GFDI = G*F - D*I;
        rtnum DHEG = D*H - E*G;

        rtnum denom = (A*EIHF + B*GFDI + C*DHEG);
        rtnum beta = (J*EIHF + K*GFDI +L*DHEG) / denom;

        if (beta <= rtnum(0.0) || beta >= rtnum(1.0)) {
                return false;
        }

        rtnum AKJB = A*K - J*B;
        rtnum JCAL = J*C - A*L;
        rtnum BLKC = B*L - K*C;

        rtnum gamma = (I*AKJB + H*JCAL + G*BLKC) / denom;
        if (gamma <= rtnum(0.0) || (beta + gamma) >= rtnum(1.0)) {
                return false;
        }

        tval = -(F*AKJB + E*JCAL + D*BLKC) / denom;
        if (tval >= t_min && tval <= t_max) {
                rec.t = tval;
                // rec.normal = unit_vector(cross((_p1 -_p0), (_p2 - _p0)));
                rec.color = _color;
                return true;
        }

        return false;
}
