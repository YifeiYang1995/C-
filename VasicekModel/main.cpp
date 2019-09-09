#include<iostream>
#include"VasicekModel.h"
#include"PathDepOption.h"
using namespace std;

int main()
{
	double a=0.25, b=0.1, sigma=0.02, r0=0.07;
	double T = 5;
	VasicekModel VM(T);
	cout << VM.D(a,b,sigma,r0) << endl;
	double m = 365;
	Vasicek option(T, m);
	long N = 1000;
	cout << "Vasicek Price = "<< option.PriceByMC(VM, N) << endl;
	system("pause");
	return 0;
}