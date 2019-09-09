#pragma once
class Stats1
{
public:
	

	void add(double x);

	double mean();
	double stdevP();

private:
	unsigned long mCount=0;
	double mSum=0.0;
	double mSum2=0.0;
};

class Stats2
{
public:
	
	void add(double x, double y);

	double covariance();
	double correlation();

	//
	//	Least-squares fit
	//
	double gradient();
	double intercept();

private:
	unsigned long mCount=0 ;
	Stats1 mX, mY;
	double mSumXY=0.0;
};




