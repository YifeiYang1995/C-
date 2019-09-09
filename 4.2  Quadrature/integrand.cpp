#include <cmath>

#include "integrand.h"

LogNormalIntegrand::LogNormalIntegrand(double S0, double r, double sigma, double T, Payoff* payoff) : m_payoff(payoff)
{
	m_m = std::log(S0) + (r - sigma * sigma / 2.0) * T;
	m_s = sigma * std::sqrt(T);
}

double LogNormalIntegrand::value(double x) 
{
	double SQRT_TWO_PI = 2.506628274631;
	double pdf = x == 0.0 ? 0.0 : 1.0 / x / m_s / SQRT_TWO_PI * std::exp(-pow(std::log(x) - m_m, 2) / 2.0 / m_s / m_s);
	double po = m_payoff->value(x);
	return pdf * po;
}
