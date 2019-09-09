#ifndef _PAYOFF_H_
#define _PAYOFF_H_

class Payoff
{
public:
	virtual double value(double S) =0;
};

class StockPayoff : public Payoff
{
public:
	StockPayoff() {};
	double value(double S)  { return S; }
};

class CallPayoff : public Payoff
{
public:
	CallPayoff(double strike) : m_strike(strike) {};
	double value(double S) 
	{
		return S > m_strike ? S - m_strike : 0.0;
	}
private:
    double m_strike;
};

class PutPayoff : public Payoff
{
public:
	PutPayoff(double strike) : m_strike(strike) {};
	double value(double S) 
	{
		return S < m_strike ? m_strike - S : 0.0;
	}
private:
	double m_strike;
};

#endif

