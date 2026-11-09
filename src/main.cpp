#include <iostream>
#include <fstream>
#include "model.h"
using namespace std;

ofstream file("/home/barash/Projects/Foucault_pendulum/src/data.csv", ios::out);


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
