
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

