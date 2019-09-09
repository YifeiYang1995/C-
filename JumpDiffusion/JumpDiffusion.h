#pragma once
#include<cmath>
class JumpDiffusion
{
public:
	double S0, K, T, sigma, r,lamdba,m,s;
	JumpDiffusion(double S0_, double K_, double T_, double sigma_, double r_, double lamdba_, double m_, double s_) :S0(S0_), K(K_), T(T_), sigma(sigma_), r(r_), lamdba(lamdba_), m(m_), s(s_) {};
	double d_plus(double S0, double sigma, double r);
	double d_minus(double S0, double sigma, double r);
	double N(double x);
	double PriceByBSFormula(double S0, double sigma, double r);
	double PriceByJDFormula(long Num);


	double k = exp(m + s*s / 2) - 1;
	double lamdba1 = lamdba*(1 + k);

};
