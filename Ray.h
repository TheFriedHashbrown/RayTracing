#ifndef RAY_H
#define RAY_H

#include<stdio.h>
#include "Vec3.h"

class Ray{
    public:
    vec3 orig;
    vec3 dir;

    Ray () {
    }

    Ray (vec3 orig, vec3 dir){
        this -> orig = orig;
        this -> dir = dir;
    }

    vec3 origin() const{
        return orig;
    }

    vec3 direction() const{
        return dir;
    }

    vec3 at (double t) const{
        vec3 ans = orig + t*dir;
        return ans;
    }
};

#endif