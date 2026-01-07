#ifndef SPHERE_H
#define SPHERE_H

#include<stdio.h>
#include "Hittable.h"
#include "Ray.h"
#include "Vec3.h"

class sphere : public Hittable{
    public :
    vec3 center;
    double radius;

    sphere () {}

    sphere (vec3 cen, double r){
        this -> center = cen;
        this -> radius = r;
    }

    bool hit(const Ray& r, double t_min, double t_max, hit_record& rec) const override{
        //According to the equation, we find out whether or not the point lies on the circle
        vec3 oc = r.origin() - center;

        double a = dot(r.direction(), r.direction());
        double b = 2.0 * dot(oc, r.direction());
        double c = dot(oc, oc) - radius*radius;

        double discriminant = b*b - 4*a*c;
        if (discriminant < 0) {
            return false;
        }

        double t1 = -b - sqrt(discriminant);
        t1 /= 2*a;
        
        double t2 = -b + sqrt(discriminant);
        t2 /= 2*a;

        if (t1 < t_min || t1 > t_max){
            if (t2 > t_max || t2 < t_min){
                return false;
            }
            rec.t = t2;
            rec.p = r.at(t2);
            rec.normal = (rec.p - center) / radius;
            return true;
        }
        rec.t = t1;
        rec.p = r.at(t1);
        rec.normal = (rec.p - center) / radius;
        return true;
    }
};

#endif