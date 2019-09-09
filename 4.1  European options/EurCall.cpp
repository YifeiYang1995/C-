#include "EurCall.h"
#include <cmath>

double EurCall::PriceByBSFormula(double S0, double sigma, double r)
{
	return S0*N(d_plus(S0, sigma, r)) - K*exp(-r*T)*N(d_minus(S0, sigma, r));
}
double EurCall::DeltaByBSFormula(double S0, double sigma, double r)
{
	return N(d_plus(S0, sigma, r));
}
double EurCall::GammaByBSFormula(double S0, double sigma, double r)
{
	return (1 / sqrt(2 * pi)*exp(-pow(d_plus(S0, sigma, r), 2) / 2)) / (S0*sigma*sqrt(T));
}

double EurCall::ThetaByBSFormula(double S0, double sigma, double r)
{
	return (-S0*(1 / sqrt(2 * pi)*exp(-pow(d_plus(S0, sigma, r), 2) / 2))*sigma) / (2 * sqrt(T)) - r*K*exp(-r*T)* N(d_minus(S0, sigma, r));
}