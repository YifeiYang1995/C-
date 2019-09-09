#ifndef _INTEGRAND_H_
#define _INTEGRAND_H_

#include "payoff.h"

class Integrand
{
public:
	virtual double value(double x)  =0;
};

class LogNormalIntegrand : public Integrand
{
public:
	LogNormalIntegrand(double S0, double r, double sigma, double T, Payoff* payoff);
	double value(double x);
private:
	double m_m, m_s;
	Payoff* m_payoff;
};

#endif

