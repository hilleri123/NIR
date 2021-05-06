

#pragma once

#include "sphere.h"

#include <vector>

class Stage
{
public:
	explicit Stage(double uG, double G, double M, double m_t);

	virtual double T_max() const;

	virtual double m(double t) const;

	virtual double G(double t) const;

	virtual ~Stage() {}
protected:
	double _uG;		//Удельный импульс
	double _G;		//Тяга
	double _M;		//Макс масса
	double _m_t; 		//Масса топлива
	//double _curr_m_t;	//Текущая масса топлива
};


class Roket
{
public:
	explicit Roket(const std::vector<Stage>& stages);
protected:
	std::vector<Stage> _stages;
};

