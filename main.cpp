#include<stdio.h>
#include<iostream>
#include<fstream>
#include "vec3.h"
#include "color.h"

int main(){
    //Setting the canvas size
    int img_width = 256;
    int img_height = 256;

    std::ofstream testFile("image.ppm");
    testFile << "P3\n" << img_width << " " << img_height << "\n255\n";
    //P3 identifes that it is a ppm file, then the width and height and 255 is the maximum colour value of a pixel in the map

    for (int i = 0; i < img_height; ++i){
        for (int j = 0; j < img_width; ++j){
            int r = double(j) / (img_width - 1);
            int g = double(i) / (img_height - 1);
            int b = 0;

            vec3 pixel_color (r, g, b);
            write_color(testFile, pixel_color);
        }
    }
    testFile.close();
}