#include<iostream>
#include"histogram.h"
#include"NRG.h"
using namespace std;

int main()
{
	
    Histogram h(-3, 3, 20);
	NRG n;
	for (unsigned int i = 0; i < 10000; ++i)
	{
		h.add(n.generate());
	}
	for (int i = 0; i < 20; ++i)
	{
		cout << h.v1[i] << endl;
	}
	system("pause");
}