#include"VasicekModel.h"
#include <cmath>

double VasicekModel::B(double a)
{
	return (1 - exp(-a*T)) / a;
}
double VasicekModel::A(double a, double b, double sigma)
{
	return (B(a) - T)*(a*a*b - 0.5*sigma*sigma) / (a*a) - pow(sigma*B(a), 2) / (4 * a);
}
double VasicekModel::D(double a, double b, double sigma, double r0)
{
	return exp(A(a,b,sigma) - B(a)*r0);
}

const double pi = 4.0*atan(1.0);
double Gauss()
{
	double U1 = (rand() + 1.0) / (RAND_MAX + 1.0);
	double U2 = (rand() + 1.0) / (RAND_MAX + 1.0);
	return sqrt(-2.0*log(U1)) * cos(2.0*pi*U2);
}
void VasicekModel::GenerateSamplePath(double T, int m, SamplePath& r)
{
	double rt = r0;
	for (int k = 0; k<m; k++)
	{
		r[k] = a*b*T / m - (a*T / m + 1)*rt + sigma*sqrt(T / m)*Gauss();
		rt = r[k];
	}
}