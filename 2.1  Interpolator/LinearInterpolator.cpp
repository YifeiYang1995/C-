#include"LinearInterpolator.h"
#include<map>
using namespace std;

void LinearInterpolator::add(double x, double y)
{
	map<double, double>::iterator it = m.find(x);
	if (it != m.end())
	{
		it->second = y;
		return;
	}
	else
	{
		m.insert(pair<double, double>(x, y));
	}
}
double LinearInterpolator::value(double x)
{
	map<double, double>::iterator it = m.begin();
	if (it->first > x)
	{
		return it->second;
	}
	++it;
	while (it != m.end())
	{
		if (it->first >= x)
		{
			double x2 = it->first;
			double y2 = it->second;
			--it;
			double x1 = it->first;
			double y1 = it->second;
			return ((x2 - x)*y1 + (x - x1)*y2) / (x2 - x1);
		}
		++it;
	}
	--it;
	return it->second;
}