
#include "roket.h"

Stage::Stage(double uG, double G, double M, double m_t)
	: _uG(uG), _G(G), _M(M), _m_t(m_t)
{}


double Stage::T_max() const
{
	return _m_t * _uG * earth::Fg(0) / _G;
}


double Stage::m(double t) const
{
	return (_M - _m_t) + (_m_t - t * _G / _uG / earth::Fg(0));
}



double Stage::G(double t) const
{
	return _G;
}





Roket::Roket(const std::vector<Stage>& stages)
	: _stages(stages)
{}

double Roket::T_max() const
{
	double res = 0;
	for (auto i = _stages.begin(); i != _stages.end(); ++i)
		res += i->T_max();
	return res;
}


double Roket::m(double t) const
{
	double tmp_t = t;
	double sum_m = 0;
	for (auto i = _stages.begin(); i != _stages.end(); ++i, tmp_t -= i->T_max()) {
		if (tmp_t < 0)
			sum_m += i->m(0);
		else if (tmp_t < i->T_max()) 
			sum_m += i->m(tmp_t);
	}
	return sum_m;
}



double Roket::G(double t) const
{
	double tmp_t = t;
	for (auto i = _stages.begin(); i != _stages.end(); ++i, tmp_t -= i->T_max())
		if (tmp_t < i->T_max())
			return i->G(tmp_t);
	return 0;
}





