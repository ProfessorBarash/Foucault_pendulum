#ifndef MODEL_H
#define MODEL_H
#include "vector.h"
#include <cmath>

Vector3 const GRAVITY_ACCELERATION{0, 0, -9.81};

class foucaultPendulum{
private:
    double string_lenght;
    const long double LATITUDE_SIN = std::sin(0.973059455), LATITUDE_COS = std::cos(0.973059455);
    const long double EARTH_T = 86164.09;
    double const OMEGA = 2 * M_PI / EARTH_T;
    public:
    angle position, velocity;
    foucaultPendulum(double string_lenght): position({0, 0.35}), velocity({0, 0}), string_lenght(string_lenght){}
    foucaultPendulum(double string_lenght, double phi_x, double phi_y): position({phi_x, phi_y}), velocity({0, 0}), string_lenght(string_lenght){}
    
    angle acceleration(angle _position, angle _velocity);
    
    void solver(double delta_t);

    Vector3 getPosition();
};

#endif