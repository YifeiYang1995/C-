#pragma once

#include"EurOption.h"
class EurCall :public EurOption
{
public:
	EurCall(double T_, double K_) { T = T_, K = K_; }
	double PriceByBSFormula(double S0, double sigma, double r);
	double DeltaByBSFormula(double S0, double sigma, double r);
	double GammaByBSFormula(double S0, double sigma, double r);
	double ThetaByBSFormula(double S0, double sigma, double r);

};

