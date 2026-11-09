#include <iostream>
#include <fstream>
using namespace std;

ofstream file("/home/barash/Projects/Foucault_pendulum/src/data.csv", ios::out);

double acceleration(double delta_x, double k=0.01){
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

int main()
{
	int i = 0;
	double delta_x = 10, delta_t = 0.1, velocity = 0;

	// while (i * delta_t < 100){
	// 	solver(delta_x, delta_t, velocity);
	// 	if (i * delta_t > 0) file << i * delta_t << ";" << delta_x << "\n";
	// 	i ++;
	// }

	while (i * delta_t < 10000){
		solver(delta_x, delta_t, velocity);
		if (i * delta_t > 9600) file << i * delta_t << ";" << delta_x << "\n";
		i ++;
	}
}
