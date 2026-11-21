#include "model.h"
#include "vector.h"
#include <cmath>

angle foucaultPendulum::acceleration(angle _position){
	double _phi = std::sqrt(std::pow(_position.phi_x, 2) + std::pow(_position.phi_y, 2));\

	if (std::abs(_phi) < 1e-5){
		return {
			- (GRAVITY_ACCELERATION.z / string_lenght) * _position.phi_x,
			- (GRAVITY_ACCELERATION.z / string_lenght) * _position.phi_y,
		};
	}

	return {
		- (GRAVITY_ACCELERATION.z / string_lenght) * std::sin(_phi) * _position.phi_x / _phi,
		- (GRAVITY_ACCELERATION.z / string_lenght) * std::sin(_phi) * _position.phi_y / _phi
	};
}

void foucaultPendulum::solver(double delta_t){
	angle k1_v, k2_v, k3_v, k4_v;
	angle k1_p, k2_p, k3_p, k4_p;

	k1_v = this->acceleration(position);
	k1_p = velocity;

	k2_v = this->acceleration(position + (delta_t / 2) * k1_p);
	k2_p = velocity + (delta_t / 2) * k1_v;

	k3_v = this->acceleration(position + (delta_t / 2) * k2_p);
	k3_p = velocity + (delta_t / 2) * k2_v;

	k4_v = this->acceleration(position + (delta_t) * k3_p);
	k4_p = velocity + (delta_t) * k3_v;

	velocity += (delta_t / 6) * k1_v + (delta_t / 3) * k2_v + (delta_t / 3) * k3_v + (delta_t / 6) * k4_v;
	position += (delta_t / 6) * k1_p + (delta_t / 3) * k2_p + (delta_t / 3) * k3_p + (delta_t / 6) * k4_p;
}