#include<stdio.h>
#include<iostream>
#include<fstream>

int main(){
    int img_width = 256;
    int img_height = 256;

    std::ofstream testFile("image.ppm");
    testFile << "P3\n" << img_width << " " << img_height << "\n255\n";

    for (int i = 0; i < img_height; ++i){
        for (int j = 0; j < img_width; ++j){
            int r = static_cast<int> (255.99 * (double(j) / (img_width - 1)));
            int g = static_cast<int> (255.99 * (double(i) / (img_height - 1)));
            int b = 0;

            testFile << r << " " << g << " " << b << "\n";
        }
    }
    testFile.close();
}