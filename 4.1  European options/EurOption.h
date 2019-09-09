#pragma once
class EurOption
{
protected:
	double T, K, pi;
public:
	double d_plus(double S0, double sigma, double r);
	double d_minus(double S0, double sigma, double r);
	double N(double x);
	virtual double PriceByBSFormula(double S0, double sigma, double r) = 0;
	virtual double DeltaByBSFormula(double S0, double sigma, double r) = 0;
	virtual double GammaByBSFormula(double S0, double sigma, double r) = 0;
	virtual double ThetaByBSFormula(double S0, double sigma, double r) = 0;
};
