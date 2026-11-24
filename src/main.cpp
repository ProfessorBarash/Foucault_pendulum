#include <iostream>
#include <fstream>
#include "model.h"
using namespace std;

ofstream file("/home/barash/Projects/Foucault_pendulum/src/data.csv", ios::out);


int main()
{
	int i = 0;
	double delta_t = 1e-2;
	foucaultPendulum pendulum(10, 0.3, 0);
    double max_value = 0;

	while (i * delta_t < 86400){
		pendulum.solver(delta_t);
		if (i * delta_t > 40000) file << i * delta_t << ";" << pendulum.getPosition().phi_x << ";" << pendulum.getPosition().phi_y << "\n";
		i ++;
	}
}
