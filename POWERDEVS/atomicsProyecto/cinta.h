//CPP:royecto.cpp
//CPP:atomicsproyecto/cinta.cpp
#if !defined cinta_h
#define cinta_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

#include "Library.h"


class cinta: public Simulator { 
// Declare the state,
// output variables
// and parameters

//parameters
int l;
int vc;

//State
//colas que guarda peso y tiempo de arribo de cada objeto
std::list<double[2]> cJ;
std::list<double[2]> cPc;
//tiempo de ejecucion
double time;

double sigma;








public:
	cinta(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif