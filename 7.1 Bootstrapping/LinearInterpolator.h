#pragma once
#include<map>
using namespace std;

class LinearInterpolator
{
public:
	LinearInterpolator() {};

	void add(double x, double y);
	double value(double x);
private:
	map<double, double> m;
};
