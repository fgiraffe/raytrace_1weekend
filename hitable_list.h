#ifndef HITABLE_LIST
#define HITABLE_LIST

#include "hitable.h"

class hitable_list : public hitable {
public:
    hitable_list() {}
    hitable_list(hitable ** l, int n) {list = l, list_size = n;}
    virtual bool hit(const ray& r, rtnum t_min, rtnum t_max,
                                            hit_record& rec) const;

    hitable    **list;
    int         list_size;
};

bool hitable_list::hit(const ray& r, rtnum t_min, rtnum t_max,
                                                hit_record& rec) const {
    hit_record temp_rec;
    bool hitAnything = false;
    double closest_so_far = t_max;

    for (size_t i = 0; i < list_size; i++) {
        if (list[i]->hit(r, t_min, closest_so_far, temp_rec)) {
            hitAnything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hitAnything;
}



#endif
