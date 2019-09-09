
#ifndef _INTEGRATOR_H_
#define _INTEGRATOR_H_

#include "integrand.h"

class Integrator
{
public:
	Integrator(double a, double b) : m_a(a), m_b(b) {};
	virtual double integrate(Integrand* integrand)  = 0;
protected:
	double m_a;
	double m_b;
};

class TrapezoidalIntegrator : public Integrator
{
public:
	TrapezoidalIntegrator(double a, double b, unsigned long N) : Integrator(a, b), m_N(N) {};
	double integrate(Integrand* integrand);
private:
	unsigned int m_N;
};

#endif

