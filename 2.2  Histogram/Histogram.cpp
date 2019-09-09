#include"histogram.h"

using namespace std;

Histogram::Histogram(double xmin, double xmax, unsigned int nbins)
{
	m_xmin = xmin;
	m_xmax = xmax;
	m_nbins = nbins;
	for (unsigned int i = 0; i < nbins; ++i)
	{
		v1.push_back(0);
	}
}

void Histogram::add(double x)
{
	if (x >= m_xmin && x < m_xmax)
	{
		v1[long(m_nbins*(x - m_xmin) / (m_xmax - m_xmin))]++;
	}
}