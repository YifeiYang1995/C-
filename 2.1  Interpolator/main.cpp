#include"LinearInterpolator.h"
#include<iostream>
#include<map>
using namespace std;

int main()
{
	LinearInterpolator L;
	L.add(0.5, 1);
	L.add(4, 5);
	L.add(1, 2);
	L.add(2, 4);
	L.add(2, 6);
	L.add(8.5, -1.0);

	cout << L.value(0.75) << " should = 1.5" << endl;

	cout << L.value(8.5) << " should = -1" << endl;

	cout << L.value(1.5) << " should = 4" << endl;

	cout << L.value(-5) << " should = 1" << endl;

	cout << L.value(20) << " should = -1" << endl;

	LinearInterpolator L2;
	L2.value(3.4);
	system("pause");
	return 0;
}