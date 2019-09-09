#pragma once

#include"VasicekModel.h"
class PathDepOption
{
public:
	double T, Price, PricingError;
	int m;
	double PriceByMC(VasicekModel Model, long N);
	
};
class Vasicek : public PathDepOption
{
public:

	Vasicek(double T_, int m_)
	{
		T = T_;  m = m_;
	}
	
};
