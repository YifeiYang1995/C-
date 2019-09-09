
#pragma once
#include<vector>
using namespace std;
class Histogram
{
public:
	Histogram(double xmin, double xmax, unsigned int nbins);
	void add(double x);
	vector<double> v1;
private:
	
	double m_xmin;
	double m_xmax;
	double m_nbins;
};


