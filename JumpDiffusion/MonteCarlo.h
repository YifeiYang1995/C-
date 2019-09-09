#pragma once
#include"JDModel.h"
class MonteCarlo
{
public:
	double T,Price, PricingError;
	int M;
	double PriceByMC(JDModel Model,long N);
	virtual double Payoff(SamplePath& S) = 0;
};
class JumpDiff :public MonteCarlo
{
public:
	JumpDiff(double T_, int M_)
	{
		T = T_; M = M_;
	}
	double Payoff(SamplePath& S);
};
