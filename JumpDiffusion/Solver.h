#pragma once
template<typename Function> double SolverByBisect(Function* Fct, double Tgt, double LEnd, double REnd, double Acc)
{
	double left = LEnd, right = REnd, mid = (left + right) / 2;
	double y_left = Fct->Value(left), y_mid = Fct->Value(mid);
	while (mid - left > Acc)
	{
		if ((y_left < Tgt&&y_mid < Tgt) || (y_left > Tgt&&y_mid > Tgt))
		{
			left = mid;
			y_left = y_mid;
		}
		else
			right = mid;
		mid = (left + right) / 2;
		y_mid = Fct->Value(mid);
	}
	return mid;
}
