#include <iostream>
#include <cmath>

#include "payoff.h"
#include "integrand.h"
#include "integrator.h"

using namespace std;

int main()
{
	//
	//	Initialise market data
	//
    double S0 = 100.0;
	double r = 0.06;
	double sigma = 0.25;

	//
	//	Option parameters
	//
	double T = 0.75;
	double K = 102.0;

	//
	//	Choose required payoff function
	//
	Payoff* payoff = new CallPayoff(K);
	//Payoff* payoff = new PutPayoff(K);
	//Payoff* payoff = new StockPayoff();

	//
	//	Build the integrand
	//
	Integrand* integrand = new LogNormalIntegrand(S0, r, sigma, T, payoff);

	double a = 0.0;
	double b = 10.0 * S0;
	unsigned int N = 100000;

	Integrator* integrator = new TrapezoidalIntegrator(a, b, N);
	double price = integrator->integrate(integrand) * exp(-r * T);
	cout << "Option price = " << price << endl;

	//
	//	From CW4 Q1, call analytic price = 9.81475
	//	Put analytic price = 7.32649
	//

	delete integrator;
	delete integrand;
	delete payoff;

	system("pause");
	return 0;
}