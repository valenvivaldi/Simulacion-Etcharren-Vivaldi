//CPP:atomicosproyecto/Library.cpp
//CPP:atomicosproyecto/conveyorbelt.cpp
#if !defined conveyorbelt_h
#define conveyorbelt_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

#include "atomicosproyecto/Library.h"


class conveyorbelt: public Simulator {
// Declare the state,
// output variables
// and parameters

//parameters
double l;
double vc;
//State
//colas que guarda peso y tiempo de arribo de cada objeto
std::list<std::pair<double,double> > cJ;
std::list<std::pair<double,double> > cPc;
//tiempo de ejecucion
double time;

double sigma;


double value1[3]; //stores the value to return in the event of a collision (only sent through port 0)
double value2[3]; //stores the value to return in the case that the end of the tape is reached (only sent through port 1)










public:
	conveyorbelt(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
