//FLAGS:-std=c++11
//CPP:atomicosproyecto/NumberGenLibrary.cpp
//CPP:atomicosproyecto/generator.cpp
#if !defined generator_h
#define generator_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

#include "atomicosproyecto/NumberGenLibrary.h"
#include "strategies.h"


class generator: public Simulator { 
// Declare the state,
// output variables
// and parameters

//parameters


int strategy;
int quantity;
unsigned int seedWeights;
unsigned int seedInterarrivals;

//state
std::list<double> weights;
std::list<double> interarrivals;

double sigma;
double aux;
public:
	generator(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
