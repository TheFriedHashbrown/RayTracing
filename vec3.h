#include<stdio.h>
#include<cmath>

class vec3{
    public:
    //Initializing an array of doubles that contain x,y,z coordinates
    double e[3];

    //Initializing the vector to a zero vector if no inputs are given
    vec3 () {
        e[0] = e[1] = e[2] = 0;
    }

    vec3 (double e0, double e1, double e2){
        e[0] = e0;
        e[1] = e1;
        e[2] = e2;
    }

    // Accessing the x,y,z values of the vector
    double x() { return e[0]; }
    double y() { return e[1]; }
    double z() { return e[2]; }

    //Operator overloading functions
    double& operator[] (int i) { return e[i]; }

    //Turns the vector opposite to it's intial state
    vec3 operator-() { return {-e[0], -e[1], -e[2]}; }

    //Vector addition
    vec3& operator+= (const vec3& obj) {
        e[0] += obj.e[0];
        e[1] += obj.e[1];
        e[2] += obj.e[2];
        return *this;
    }

    //Scalar multiplication
    vec3& operator*= (double t){
        e[0] *= t; e[1] *= t; e[2] *= t;
        return *this;
    }

    //Scalar division
    vec3& operator/= (double t){
        double div = 1.0/t;
        e[0] *= div; e[1] *= div; e[2] *= div;
        return *this;
    }

    //Calculating magnitude of the vector
    double length () const {
        return sqrt (e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
    }
};

//Output Stream (Printing)
inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

//Vector Addition (v1 + v2)
inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

//Vector Subtraction (v1 - v2)
inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

//Component-wise Multiplication (v1 * v2)
inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

//Scalar Multiplication (v * t)
inline vec3 operator*(const vec3 &v, double t) {
    return vec3(v.e[0] * t, v.e[1] * t, v.e[2] * t);
}

//Scalar Multiplication (t * v) - Allows writing "5.0 * v"
inline vec3 operator*(double t, const vec3 &v) {
    return vec3(v.e[0] * t, v.e[1] * t, v.e[2] * t);
}

//Scalar Division (v / t)
inline vec3 operator/(vec3 v, double t) {
    double div = 1.0 / t;
    return vec3(v.e[0] * div, v.e[1] * div, v.e[2] * div);
}

//Dot product
inline double dot (const vec3& v, const vec3& u){
    return u.e[0] * v.e[0]
        + u.e[1] * v.e[1]
        + u.e[2] * v.e[2];
}

//Cross product
inline vec3 cross (vec3& u, vec3& v){
    return vec3 (u.e[1] * v.e[2] - u.e[2] * v.e[1],
        u.e[2] * v.e[0] - u.e[0] * v.e[2],
        u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

//Unit vector
inline vec3 unit_vector (vec3 v){
    return v / v.length();
}