#include "PathDepOption.h"
#include <cmath>
#include<iostream>
using namespace std;
double PathDepOption::PriceByMC(VasicekModel Model, long N)
{
	double H = 0.0, Hsq = 0.0;
	SamplePath r(m);
	for (long i = 0; i<N; i++)
	{
		Model.GenerateSamplePath(T, m, r);
		H = (i*H + Payoff(r)) / (i + 1.0);
		Hsq = (i*Hsq + pow(Payoff(r), 2.0)) / (i + 1.0);
	}
	double a = 0.25, b = 0.1, sigma = 0.02, r0 = 0.07;
	Price = Model.D(a, b, sigma, r0)*H;
	PricingError = Model.D(a, b, sigma, r0)*sqrt(Hsq - H*H) / sqrt(N - 1.0);
	cout << PricingError << endl;
	return Price;
}
