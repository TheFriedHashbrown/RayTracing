#ifndef HITTABLELIST_H
#define HITTABLELIST_H

#include<stdio.h>
#include<vector>
#include<memory>
#include "Hittable.h"
#include "Ray.h"
#include "Vec3.h"

using namespace std;

class hittable_list : public Hittable{
    public:
    vector<shared_ptr<Hittable>> objects;
    
    void add_object(shared_ptr<Hittable> object){
        objects.push_back(object); return;
    }

    bool hit(const Ray& r, double t_min, double t_max, hit_record& rec) const override{
        hit_record temp_rec;
        bool hit_anything = false;
        double closest = t_max;

        for (const auto& obj : objects){
            if (obj -> hit(r, t_min, closest, temp_rec)){
                hit_anything = true;
                closest = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit_anything;
    }
};

#endif