#pragma once

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


//****************************************************************

void Stats2::add(double x, double y)
{
	mX.add(x);
	mY.add(y);
	mSumXY += x * y;
	mCount++;
	return;
}


double Stats2::covariance()
{
	
	double cov = mSumXY / mCount - mX.mean() * mY.mean();
	return cov;
}

double Stats2::correlation()
{
	
    double cov = covariance();
    double denom = mX.stdevP() * mY.stdevP();
	
	return cov / denom;
}

double Stats2::gradient() 
{
	
	double cov = covariance();
	double varX = mX.stdevP() * mX.stdevP();
	
	return cov / varX;
}

double Stats2::intercept() 
{
	
	return mY.mean() - gradient() * mX.mean();
}

