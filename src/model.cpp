#include "model.h"

double acceleration(double delta_x, double k){
	return -k * delta_x;
}

void solver(double& delta_x, double delta_t, double& velocity){
	double k1_v, k2_v, k3_v, k4_v;
	double k1_x, k2_x, k3_x, k4_x;
	
	k1_v = acceleration(delta_x);
	k1_x = velocity;

	k2_v = acceleration(delta_x + k1_x * delta_t / 2);
	k2_x = velocity + k1_v * delta_t / 2;

	k3_v = acceleration(delta_x + k2_x * delta_t / 2);
	k3_x = velocity + k2_v * delta_t / 2;

	k4_v = acceleration(delta_x + k3_x * delta_t);
	k4_x = velocity + k3_v * delta_t;

	velocity += delta_t * k1_v / 6 + delta_t * k2_v / 3 + delta_t * k3_v / 3 + delta_t * k4_v / 6;
	delta_x += delta_t * k1_x / 6 + delta_t * k2_x / 3 + delta_t * k3_x / 3 + delta_t * k4_x / 6;
}