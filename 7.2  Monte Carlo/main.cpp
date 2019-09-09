#include <cmath>
#include<iostream>
#include "stats1.h"
using namespace std;

int main()
{
	Stats1 S;
	const double pi = 4*atan(1);
	double ASquare = 64;
	for (int i = 0; i < 1000000; i++)
	{
		double x = ((double)rand() / RAND_MAX) * 8-4;
		double y = ((double)rand() / RAND_MAX) * 8-4;
		double r = sqrt(x*x + y*y);
		if (abs(r) <= 3 - cos(8 * atan(y / x)))
			S.add(1);
		else
			S.add(0);
	}
		

	cout << S.mean()*ASquare<<endl;

	cout << S.stdevP() / sqrt(1000000)*ASquare;
	
	system("pause");
	return 0;
}