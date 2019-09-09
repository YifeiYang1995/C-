#include"NRG.h"
#include<random>
#include<time.h>
using namespace std;

double NRG::generate()
{
	double u1 = rand() / double(RAND_MAX);
	double u2 = rand() / double(RAND_MAX);
	const double pi = 3.14159265358979323846;
	return sqrt(-2 * log(u1))*cos(2 * pi * u2);
}