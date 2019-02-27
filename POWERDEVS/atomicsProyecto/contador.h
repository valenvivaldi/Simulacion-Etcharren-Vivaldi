//CPP:atomicsproyecto/contador.cpp
#if !defined contador_h
#define contador_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

#include "limits"
#include "iostream"


class contador: public Simulator { 
// Declare the state,
// output variables
// and parameters

int colWinJ;
int colWinPc;
int colTie;


int arrivalPc;
int arrivalJ;

	
double sigma;
public:
	contador(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
