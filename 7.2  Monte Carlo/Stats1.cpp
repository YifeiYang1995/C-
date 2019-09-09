#include <cmath>

#include "stats1.h"

void Stats1::add(double x)
{
	
    mSum += x;
	mSum2 += x * x;
	mCount++;
	return;
}


double Stats1::mean()
{

	return mSum / mCount;
}

double Stats1::stdevP()
{

	double m = mean();
	return sqrt(mSum2 / mCount - m * m);
}