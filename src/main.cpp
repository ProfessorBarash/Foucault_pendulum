#include <iostream>
#include <fstream>
#include "model.h"
using namespace std;

ofstream file("/home/barash/Projects/Foucault_pendulum/src/data.csv", ios::out);


int main()
{
	int i = 0;
	double delta_t = 1e-2;
	foucaultPendulum pendulum(10, 0, 1);
	cout << abs(pendulum.getPosition().z) << endl;
    double max_value = 1000;

	while (i * delta_t < 86400){
		pendulum.solver(delta_t);
		if (i * delta_t > 80000){
			file << i * delta_t << ";" << pendulum.getPosition().x << ";" << pendulum.getPosition().y << "\n";
			if (abs(pendulum.getPosition().z) < max_value){
				max_value = abs(pendulum.getPosition().z);
			}
			// cout << pendulum.position.phi_x << " " << pendulum.position.phi_y << endl;
		}
		i ++;
	}
	cout << max_value << endl;
}
