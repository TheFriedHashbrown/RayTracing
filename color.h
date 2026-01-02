#include<stdio.h>
#include<vec3.h>

inline std::ostream& write_color(std::ostream &out, const vec3& pixel_color) {
    double r = pixel_color.x();
    double g = pixel_color.y();
    double b = pixel_color.z();

    int red = static_cast<int>(255.99 * r);
    int green = static_cast<int>(255.99 * g);
    int blue = static_cast<int>(255.99 * b);

    return out << red << ' ' << green << ' ' << blue << "\n";
}