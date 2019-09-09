#include "integrator.h"

double TrapezoidalIntegrator::integrate(Integrand* integrand)
{
	double h = (m_b - m_a) / m_N;

	double integral = 0.0;
	for (unsigned long i = 0; i <= m_N; i++)
	{
		double S = m_a + i * h;
		double y = integrand->value(S);
		integral += y;
	}
	integral += (integrand->value(m_a) + integrand->value(m_b)) / 2.0;
	return integral * h;
}