#include <cmath>
#include <iostream>
#include <fstream>
#include "model.h"
using namespace std;

ofstream file("/home/barash/Projects/Foucault_pendulum/src/data.csv", ios::out);


int main()
{
	int i = 0;
	double delta_t = 1e-2;
	foucaultPendulum pendulum1(10, 0.3 / sqrt(2), 0.3 / sqrt(2));
	foucaultPendulum pendulum2(10, 0.3, 0);
	foucaultPendulum pendulum3(10, 0, 0.3);
    double max_value = 0;

	while (i * delta_t < 1000){
		pendulum1.solver(delta_t);
		pendulum2.solver(delta_t);
		pendulum3.solver(delta_t);
		if (i * delta_t > 900) file << i * delta_t << ";" << pendulum1.getPosition().phi_y << ";" << pendulum2.position.phi_x << ";" << pendulum3.position.phi_y << "\n";
		i ++;
	}
}
