#include"JDModel.h"
#include<cmath>
#include<iostream>
const double PI = 4 * atan(1);
double Gauss()
{
	double U1 = (rand() + 1.0) / (RAND_MAX + 1.0);
	double U2 = (rand() + 1.0) / (RAND_MAX + 1.0);
	return sqrt(-2.0*log(U1)) * cos(2.0*PI*U2);
}
void JDModel::GenerateSamplePath(double T, int M, SamplePath& S)
{
	double St = S0;
	double alpha = r - sigma*sigma / 2 - lamdba*(exp(m + s*s / 2) - 1);
	for (int k = 0; k < M; k++)
	{
		double u = (rand() + 0.5) / (RAND_MAX + 1.0);
		if (u <= (lamdba*T / M))
		{
			S[k] = exp(Gauss()*s + m)*St*exp(alpha*T / M + sigma*sqrt(T / M)*Gauss());
			St = S[k];
		}
		else
		{
			S[k] = St*exp(alpha*T / M + sigma*sqrt(T / M)*Gauss());
			St = S[k];
		}
	
	}
}