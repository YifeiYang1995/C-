#include<iostream>
#include"JumpDiffusion.h"
#include"JDModel.h"
#include"MonteCarlo.h"
#include"Solver.h"
using namespace std;

class F
{
public:
	double Value(double x)
	{
		double S0 = 100, K = 105, T = 0.5, sigma = 0.15, r = 0.05, lamdba = 1, m = 0.05, s = 0.3;
		JumpDiffusion JDmodel(S0, K, T, sigma, r, lamdba, m, s);
		return JDmodel.PriceByBSFormula(S0, x, r);
	}
}MyF;
int main()
{
	/*double S0=100, K=105, T=0.5, sigma=0.15, r=0.05, lamdba=1, m=0.05, s=0.3;
	JumpDiffusion JDmodel(S0, K, T, sigma, r, lamdba, m, s);
	long Num = 100;
	cout << JDmodel.PriceByJDFormula(Num) << endl;
	cout << JDmodel.PriceByBSFormula(S0,sigma,r) << endl;

	JDModel model(S0, sigma, r, lamdba, m, s);
	int M = 365;
	JumpDiff JD(T, M);
	long N = 7600000;
	cout << "PriceByMC= " << JD.PriceByMC(model, N) << endl;*/

	
	double Acc = 0.001;
	double LEnd = 0.0, REnd = 1.0;
	double Tgt = 3.18;
	cout << SolverByBisect(&MyF, Tgt, LEnd, REnd, Acc);
	system("pause");
	return 0;
}