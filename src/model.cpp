#include "model.h"
#include "vector.h"
#include <cmath>

angle foucaultPendulum::acceleration(angle _position, angle _velocity){
	long double Omega_z = OMEGA * LATITUDE_SIN;
	long double Omega_y = OMEGA * LATITUDE_COS;

	// trigonometry
	long double tg_phi_x = std::tan(_position.phi_x), tg_phi_y = std::tan(_position.phi_y);

	// values
	long double D = std::hypot(tg_phi_x, tg_phi_y, 1);
	long double z;
	z = - string_lenght / D;


	long double x_dot, y_dot, z_dot, D_dot;
	D_dot = (_velocity.phi_x * tg_phi_x * (1 + std::pow(tg_phi_x, 2)) + _velocity.phi_y * tg_phi_y * (1 + std::pow(tg_phi_y, 2)));
	D_dot /= D;
	x_dot = string_lenght * (_velocity.phi_x * D * (1 + std::pow(tg_phi_x, 2)) - D_dot * tg_phi_x) / (D * D);
	y_dot = string_lenght * (_velocity.phi_y * D * (1 + std::pow(tg_phi_y, 2)) - D_dot * tg_phi_y) / (D * D);
	z_dot = string_lenght * D_dot / (D * D);

	long double phi_x_acceleration = 2 * (Omega_z * y_dot - Omega_y * z_dot + Omega_y * tg_phi_x * x_dot) + GRAVITY_ACCELERATION.z * tg_phi_x;
	long double phi_y_acceleration = 2 * (Omega_y * x_dot * tg_phi_y - Omega_z * x_dot) + GRAVITY_ACCELERATION.z * tg_phi_y;

	phi_x_acceleration *= -1/(1 + tg_phi_x * tg_phi_x);
	phi_y_acceleration *= -1/(1 + tg_phi_y * tg_phi_y);

	phi_x_acceleration -= 2 * z_dot * _velocity.phi_x + 2 * z * std::pow(_velocity.phi_x, 2) * tg_phi_x;
	phi_y_acceleration -= 2 * z_dot * _velocity.phi_y + 2 * z * std::pow(_velocity.phi_y, 2) * tg_phi_y;

	phi_x_acceleration /= z;
	phi_y_acceleration /= z;

	// std::cout << (x_dot * x_dot + y_dot * y_dot + z_dot * z_dot) / 2 - z * GRAVITY_ACCELERATION.z << "\n";

	return {
		phi_x_acceleration, 
		phi_y_acceleration
	};
}

void foucaultPendulum::solver(double delta_t){
	angle k1_v, k2_v, k3_v, k4_v;
	angle k1_p, k2_p, k3_p, k4_p;

	k1_v = this->acceleration(position, velocity);
	k1_p = velocity;

	k2_p = velocity + (delta_t / 2) * k1_v;
	k2_v = this->acceleration(position + (delta_t / 2) * k1_p, k2_p);

	k3_p = velocity + (delta_t / 2) * k2_v;
	k3_v = this->acceleration(position + (delta_t / 2) * k2_p, k3_p);

	k4_p = velocity + (delta_t) * k3_v;
	k4_v = this->acceleration(position + (delta_t) * k3_p, k4_p);

	velocity += (delta_t / 6) * k1_v + (delta_t / 3) * k2_v + (delta_t / 3) * k3_v + (delta_t / 6) * k4_v;
	position += (delta_t / 6) * k1_p + (delta_t / 3) * k2_p + (delta_t / 3) * k3_p + (delta_t / 6) * k4_p;
}

Vector3 foucaultPendulum::getPosition(){
	long double D = std::hypot(std::tan(position.phi_x), std::tan(position.phi_y), 1);
	return {
		string_lenght * std::tan(position.phi_x) / D,
		string_lenght * std::tan(position.phi_y) / D,
		- string_lenght / D
	};
}