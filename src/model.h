#ifndef MATH_UTILS_H
#define MATH_UTILS_H

double acceleration(double delta_x, double k=0.01);

void solver(double& delta_x, double delta_t, double& velocity);

#endif