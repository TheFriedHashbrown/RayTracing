#include<stdio.h>
#include<iostream>
#include<fstream>
#include "Vec3.h"
#include "Color.h"
#include "Ray.h"

vec3 ray_color();

int main(){
    //Setting the canvas size
    int img_width = 256;
    int img_height = 256;

    std::ofstream testFile("image.ppm");
    testFile << "P3\n" << img_width << " " << img_height << "\n255\n";
    //P3 identifes that it is a ppm file, then the width and height and 255 is the maximum colour value of a pixel in the map



    for (int i = 0; i < img_height; ++i){
        for (int j = 0; j < img_width; ++j){
            double r = double(j) / (img_width - 1);
            double g = double(i) / (img_height - 1);
            double b = 0;

            vec3 pixel_color (r, g, b);
            write_color(testFile, pixel_color);
        }
    }
    testFile.close();
}

//Writing a function for the background
vec3 ray_color (const Ray& r){
    //Normalizes the vector to have a y value from -1 to 1
    vec3 unit = unit_vector(r.direction());
    
    //Scales it from 0 to 1 so that we can use t as percentage
    double t = 0.5 * (unit.y() + 1);

    //Creating a gradient from white to blue for the background
    vec3 start_val = vec3(1.0, 1.0, 1.0);
    vec3 end_val = vec3(0.5, 0.7, 1.0);
    return ((1.0 - t) * start_val) + (t * end_val);
}