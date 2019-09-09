#pragma once
class Stats1
{
public:


	void add(double x);

	double mean();
	double stdevP();

private:
	unsigned long mCount = 0;
	double mSum = 0.0;
	double mSum2 = 0.0;
};
