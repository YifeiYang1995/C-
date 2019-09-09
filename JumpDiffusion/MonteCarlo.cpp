#include"MonteCarlo.h"
#include<cmath>
#include<iostream>
using namespace std;
double JumpDiff::Payoff(SamplePath& S)
{
	double K = 105;
	return S[M - 1] - K > 0 ? S[M - 1] - K : 0;
}
double MonteCarlo::PriceByMC(JDModel Model, long N)
{
	double H = 0.0, Hsq = 0.0;
	SamplePath S(M);
	for (int i = 0; i < N; i++)
	{
		Model.GenerateSamplePath(T, M, S);
		H = (i*H + Payoff(S)) / (i + 1);
		Hsq = (i*Hsq + pow(Payoff(S), 2)) / (i + 1);
	}
	Price = exp(-Model.r*T)*H;
	PricingError = exp(-Model.r*T)*sqrt(Hsq - H*H) / sqrt(N - 1);
	cout << "PricingError= " << PricingError << endl;
	return Price;
} 
