#ifndef HITTABLE_H
#define HITTABLE_H

#include<stdio.h>
#include "Vec3.h"
#include "Ray.h"

struct hit_record{
    vec3 p;
    vec3 normal;
    double t;
};

class Hittable{
    public:
    virtual bool hit (const Ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif