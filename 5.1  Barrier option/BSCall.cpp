#include "UpAndOutEurCall.h"

#include<math.h>
#include<iostream>

#include<vector>
using namespace std;

double UpAndOutEurCall::N(double x)
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
double UpAndOutEurCall::Dd(double y, double r, double Sigma)
{
	return (log(y) + (r + 0.5*pow(Sigma, 2))*T) / (Sigma*sqrt(T));
}
double UpAndOutEurCall::dEven(double x, double Sigma)
{
	return x - Sigma*sqrt(T);
}
double UpAndOutEurCall::PriceByBSFormula(double S0, double r, double Sigma)
{
	return S0*(N(Dd(S0/K, r, Sigma)) - N(Dd(S0/B, r, Sigma)) - pow(B / S0, 1 + 2 * r / pow(Sigma, 2))*(N(dEven(Dd(S0 / B, -r, Sigma),Sigma)) - N(dEven(Dd(S0*K / (B*B), -r, Sigma),Sigma)))) - K*exp(-r*T)*(N(dEven(Dd(S0 / K, r, Sigma), Sigma)) - N(dEven(Dd(S0 / B, r, Sigma), Sigma)) - pow(B / S0, -1 + 2 * r / pow(Sigma, 2))*(N(Dd(S0/B, -r, Sigma)) - N(Dd(S0*K / (B*B), -r, Sigma))));
}

int UpAndOutEurCall::GetInputData(int& N)
{
	cout << "Enter steps to expiry N: "; cin >> N;
	cout << endl;
	return 0;
}
double UpAndOutEurCall::delta( int N)
{
	return T / N;
}
double UpAndOutEurCall::R(double r, int N)
{
	return exp(r*delta(N)) - 1;
}
double UpAndOutEurCall::U(double Sigma, double r, int N)
{
	return exp((r - 0.5*pow(Sigma, 2))*delta(N) + Sigma*sqrt(delta( N)));
}
double UpAndOutEurCall::D(double Sigma, double r, int N)
{
	return exp((r - 0.5*pow(Sigma, 2))*delta( N) - Sigma*sqrt(delta(N)));
}
double UpAndOutEurCall::RiskNeutProb(double Sigma, double r, int N)
{
	return (R(r, N) - D(Sigma, r, N)) / (U(Sigma, r, N) - D(Sigma, r, N));
}
double UpAndOutEurCall::S(double S0, int n, int i, double Sigma, double r, int N)
{
	return S0*pow(1 + D(Sigma, r, N), i)*pow(1 + D(Sigma, r, N), n - i);
}
double UpAndOutEurCall::PriceByCRR(double S0, double Sigma, double r, int N)
{
	double q = RiskNeutProb(Sigma, r, N);
	vector<double> Price;
	for (unsigned int i = 0; i < N+1; i++)
	{
		Price.push_back(CallPayoff(S(S0, N, i, Sigma, r, N)));
	}
	for (int n = N - 1; n >= 0; n--)
	{
		for (int i = 0; i <= n; i++)
		{
			Price.push_back((q*Price[i + 1] + (1 - q)*Price[i]) / (1 + R(r, N)));
		}
	}
	return Price[0];
}
double UpAndOutEurCall::CallPayoff(double z)
{
	if (z>K) return z - K;
	return 0.0;
}