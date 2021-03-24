
#pragma once

#include <functional>

// y' = f(x, y)
// y' - RES, x - ARG0, y - ARG1
//RES f(ARG0 x, ARG1 y)

template<class ARG0, class ARG1>
class ArgsContainer
{
public:
	ArgsContainer(const ARG0& x, const ARG1& y) : _x(x), _y(y)
	{}

	ArgsContainer() : _x(ARG0()), _y(ARG1())
	{}

	ArgsContainer(const ArgsContainer&) = default;
	ArgsContainer(ArgsContainer&&) = default;
	ArgsContainer& operator=(const ArgsContainer&) = default;
	ArgsContainer& operator=(ArgsContainer&&) = default;

	ARG0& x() { return _x; } 
	ARG1& y() { return _y; } 
protected:
	ARG0 _x;
	ARG1 _y;
};

template<class RES, class ARG0, class ARG1>
class OdeSolver
{
public:
	using Args = ArgsContainer<ARG0, ARG1>;
	explicit OdeSolver(RES (*f_ptr)(ARG0, ARG1), const Args& initial) : _f_ptr(f_ptr), _initial(initial)
	{
		reset();
	}

	void reset() { _current = _initial; }

	void set_step(ARG0 step) { _step = step; }

	virtual RES step()
	{
		return RES();
	}

	virtual ~OdeSolver() {}

protected:

	std::function<RES(ARG0, ARG1)> _f_ptr;
	//ArgsContainer<ARG0, ARG1> _initial;
	//ArgsContainer<ARG0, ARG1> _current;
	Args _initial;
	Args _current;
	ARG0 _step;
};

