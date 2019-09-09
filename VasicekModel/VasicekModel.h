#pragma once
#include<cmath>
#include<ctime>
using namespace std;
#include<vector>
typedef vector<double> SamplePath;

class VasicekModel
{
public:
	VasicekModel(double T_)  
	{
		T = T_;
		srand(time(NULL));
	}

	void GenerateSamplePath(double T, int m, SamplePath& r);

	double B(double a);
	double A(double a, double b, double sigma);
	double D(double a,double b,double sigma,double r0); 


	double T;
	double a, b, sigma, r0;


};
