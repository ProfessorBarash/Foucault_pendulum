#ifndef MODEL_H
#define MODEL_H
#include "vector.h"

Vector3 const GRAVITY_ACCELERATION{0, 0, 9.81};

class foucaultPendulum{
private:
    
    double string_lenght;
public:
    angle position, velocity;
    foucaultPendulum(double string_lenght): position({0, 0.35}), velocity({0, 0}), string_lenght(string_lenght){}
    foucaultPendulum(double string_lenght, double phi_x, double phi_y): position({phi_x, phi_y}), velocity({0, 0}), string_lenght(string_lenght){}
    
    angle acceleration(angle _position);
    
    void solver(double delta_t);

    angle getPosition(){
        return position;
    }
};

#endif