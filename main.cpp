#include<stdio.h>
#include<iostream>
#include<fstream>
#include "Vec3.h"
#include "Color.h"
#include "Ray.h"

bool hit_sphere (const vec3& center, double radius, const Ray& r);
vec3 ray_color(const Ray& r);

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

    for (int i = img_height - 1; i >= 0 ; i--)
    {
        for (int j = 0; j < img_width; j++){
            //Converting it into percentages that are then used to find the x and y components of the vector
            double u = double(j) / (img_width - 1);
            double v = double(i) / (img_height - 1);

            vec3 dir = bottom_left_corner + u*horizontal + v*vertical - origin;

            Ray r(origin, dir);
            vec3 pixel_color = ray_color(r);
            write_color (testFile, pixel_color);
        }
    }
    
    testFile.close();
}

//Writing a function for the background
vec3 ray_color (const Ray& r){
    if (hit_sphere(vec3(0, 0, -1), 0.25, r)){
        return vec3(1, 0, 0);
    }

    //Normalizes the vector to have a y value from -1 to 1
    vec3 unit = unit_vector(r.direction());
    
    //Scales it from 0 to 1 so that we can use t as percentage
    double t = 0.5 * (unit.y() + 1);

    //Creating a gradient from white to blue for the background
    vec3 start_val = vec3(1.0, 1.0, 1.0);
    vec3 end_val = vec3(0.5, 0.7, 1.0);
    return ((1.0 - t) * start_val) + (t * end_val);
}

bool hit_sphere (const vec3& center, double radius, const Ray& r){
    //According to the equation, we find out whether or not the point lies on the circle
    vec3 oc = r.origin() - center;

    double a = dot(r.direction(), r.direction());
    double b = 2.0 * dot(oc, r.direction());
    double c = dot(oc, oc) - radius*radius;

    double discriminant = b*b - 4*a*c;
    return (discriminant > 0);
}