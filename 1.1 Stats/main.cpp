#include <iostream>
#include <cmath>

#include "stats1.h"

using namespace std;

int main()
{
	//
	//	Question 1(a)
	//
	Stats1 s1;
	for (unsigned int i = 0; i < 10000; ++i)
	{
	    
		s1.add((rand()) /double(RAND_MAX));
	}
	cout << "Mean of values = " << s1.mean() << endl;
	cout << "Stdev of values = " << s1.stdevP() << endl;

	//
	//	Question 1(c)
	//
	Stats2 s2;
	s2.add(1, 16);
	s2.add(2, 11);
	s2.add(3, 9);
	s2.add(4, 3);
	s2.add(5, 2);

	cout << "Gradient = " << s2.gradient() << endl;
	cout << "Intercept = " << s2.intercept() << endl;

	double corr = s2.correlation();
	cout << "R2 = " << corr * corr << endl;

	system("pause");
	return 0;
}


