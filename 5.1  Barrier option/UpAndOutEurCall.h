#pragma once

class UpAndOutEurCall
{
public:
	double N(double x);
	double Dd(double y, double r, double Sigma);
	double PriceByBSFormula(double S0, double r, double Sigma);
    double dEven(double x,double Sigma);

	double delta(int N);
	double R(double r,int N);
	double S(double S0, int n, int i, double Sigma, double r, int N);
	double U(double Sigma, double r, int N);
	double RiskNeutProb(double Sigma, double r, int N);
	
	double D(double Sigma, double r, int N);
	int GetInputData(int& N);
	double PriceByCRR(double S0, double Sigma, double r, int N);
	double CallPayoff(double z);
private:
	double K = 100, B = 130, T = 1;
	double x = 0;
};

