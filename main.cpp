#include<stdio.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<memory>
#include <cmath>
#include<limits>

#include "Vec3.h"
#include "Color.h"
#include "Ray.h"
#include "Hittable.h"
#include "Sphere.h"
#include "HittableList.h"

vec3 ray_color(const Ray& r, Hittable& obj);

int main(){
    //Setting the canvas size
    int img_width = 256;
    int img_height = 256;

    std::ofstream testFile("image.ppm");
    testFile << "P3\n" << img_width << " " << img_height << "\n255\n";
    //P3 identifes that it is a ppm file, then the width and height and 255 is the maximum colour value of a pixel in the map

    auto aspect_ratio = double(img_width) / img_height;
    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;
    vec3 origin = vec3 (0, 0, 0);
    vec3 horizontal = vec3 (viewport_width, 0, 0);
    vec3 vertical = vec3 (0, viewport_height, 0);
    vec3 bottom_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

    hittable_list world;
    world.add_object(make_shared<sphere>(vec3(0, 0, -1), 0.5));
    world.add_object(make_shared<sphere>(vec3(0, -100.5, -1), 100));

    for (int i = img_height - 1; i >= 0 ; i--)
    {
        for (int j = 0; j < img_width; j++){
            //Converting it into percentages that are then used to find the x and y components of the vector
            double u = double(j) / (img_width - 1);
            double v = double(i) / (img_height - 1);

            vec3 dir = bottom_left_corner + u*horizontal + v*vertical - origin;

            Ray r(origin, dir);
            vec3 pixel_color = ray_color(r, world);
            write_color (testFile, pixel_color);
        }
    }
    
    testFile.close();
}

vec3 ray_color (const Ray& r, Hittable& obj){
    hit_record record;
    bool present = obj.hit(r, 0.001, std::numeric_limits<double>::infinity(), record);
    
    if (present){
        vec3 normal = 0.5 * (unit_vector(record.normal) + vec3(1, 1, 1));
        return normal;
    }
    
    vec3 unit = unit_vector(r.direction());
    double val = 0.5 * (unit.y() + 1);

    vec3 end_val = vec3(0.5, 0.7, 1.0);
    vec3 start_val = vec3(1.0, 1.0, 1.0);

    return (1 - val) * start_val + val * end_val;
}