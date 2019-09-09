#include<iostream>
#include"UpAndOutEurCall.h"
using namespace std;
int main()
{
	UpAndOutEurCall a;
	cout << a.PriceByBSFormula(98, 0.05, 0.2) << endl;



	int N; //steps to expiry
	cout << "Enter call option data:" << endl;
	a.GetInputData(N);
	cout << "European call option price = " << a.PriceByCRR(98, 0.05, 0.2, N) << endl;
	system("pause");
	return 0;
}
