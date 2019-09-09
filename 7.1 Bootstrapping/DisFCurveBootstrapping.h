#pragma once
class DiscountCurve
{
public:
	void insert(double T,double DT);
	double getDF(double T);
};

class Swap{
	double price(const DiscountCurve& dc);
	double parRate(DiscountCurve& dc);
};

class Bootstrapper
{

};
