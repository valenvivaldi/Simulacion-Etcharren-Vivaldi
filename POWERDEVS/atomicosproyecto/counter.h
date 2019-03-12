//CPP:atomicosproyecto/counter.cpp
#if !defined counter_h
#define counter_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

#include "limits"
#include "iostream"


class counter: public Simulator { 
// Declare the state,
// output variables
// and parameters

int colWinJ;
int colWinPc;
int colTie;


int arrivalPc;
int arrivalJ;

int portEmit;
double aux;

double sigma;
public:
	counter(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
