//CPP:atomicosproyecto/simplegenerator.cpp
#if !defined simplegenerator_h
#define simplegenerator_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"



class simplegenerator: public Simulator { 
// Declare the state,
// output variables
// and parameters




//state
//std::vector<double> weights;
//std::vector<double> interarrivals;

//int dispatched;
double sigma;
double aux;
public:
	simplegenerator(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
