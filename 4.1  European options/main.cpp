#include"EurCall.h"
#include"EurPut.h"
#include"EurOption.h"
#include<iostream>
using namespace std;

int main()
{
	double S0 = 100.0;
	double r = 0.06;
	double T = 0.75;
	double K = 102.0;
	EurCall c(T, K);
	cout << c.PriceByBSFormula(S0, 0.25, r) << endl;
	cout << c.DeltaByBSFormula(S0, 0.25, r) << endl;
	cout << c.GammaByBSFormula(S0, 0.25, r) << endl;
	cout << c.ThetaByBSFormula(S0, 0.25, r) << endl;
	EurPut p(T, K);
	cout << p.PriceByBSFormula(S0, 0.25, r) << endl;
	cout << p.DeltaByBSFormula(S0, 0.25, r) << endl;
	cout << p.GammaByBSFormula(S0, 0.25, r) << endl;
	cout << p.ThetaByBSFormula(S0, 0.25, r) << endl;
	system("pause");
	return 0;
}