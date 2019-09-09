#pragma once
#include<vector>
#include<ctime>
using namespace std;
typedef vector<double> SamplePath;

class JDModel
{
public:
	double S0, sigma, r, lamdba, m, s;
	JDModel(double S0_,double sigma_, double r_, double lamdba_, double m_, double s_)
	{
		S0 = S0_; sigma = sigma_; r = r_; lamdba = lamdba_; m = m_; s = s_;
		srand(time(NULL));
	}
	void GenerateSamplePath(double T, int M, SamplePath& S);
};