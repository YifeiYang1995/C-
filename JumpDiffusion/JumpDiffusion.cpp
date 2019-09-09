#include"JumpDiffusion.h"
#include<cmath>

double JumpDiffusion::N(double x)
{
	double gamma = 0.2316419; double a1 = 0.319381530;
	double a2 = -0.356563782; double a3 = 1.781477937;
	double a4 = -1.821255978; double a5 = 1.330274429;
	double pi = 4.0*atan(1.0); double k = 1.0 / (1.0 + gamma*x);
	if (x >= 0.0)
	{
		return 1.0 - ((((a5*k + a4)*k + a3)*k + a2)*k + a1)
			*k*exp(-x*x / 2.0) / sqrt(2.0*pi);
	}
	else return 1.0 - N(-x);
}

double JumpDiffusion::d_plus(double S0, double sigma, double r)
{
	return (log(S0 / K) + (r + 0.5*pow(sigma, 2.0))*T) / (sigma*sqrt(T));
}
double JumpDiffusion::d_minus(double S0, double sigma, double r)
{
	return d_plus(S0, sigma, r) - sigma*sqrt(T);
}
double JumpDiffusion::PriceByBSFormula(double S0, double sigma, double r)
{

	return S0*N(d_plus(S0, sigma, r)) - K*exp(-r*T)*N(d_minus(S0, sigma, r));
}
double JumpDiffusion::PriceByJDFormula(long Num)
{
	int n=0;
	
	double sum = 0;
	for (; n < Num; n++)
	{
		double mul = 1;
		for (int i = 1; i < n + 1; i++)
			mul *= i;
		double sigma_n = sqrt(sigma*sigma + n*s*s / T);
		double r_n = r - lamdba*k + n*log(1 + k) / T;
		sum += exp(-lamdba1*T)*pow(lamdba1*T, n) / mul*PriceByBSFormula(S0, sigma_n, r_n);
	}
	return sum;
}
