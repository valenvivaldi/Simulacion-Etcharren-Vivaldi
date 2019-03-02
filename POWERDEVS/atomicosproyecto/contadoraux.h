//FLAGS:-std=c++11
//CPP:proyecto/SimulatorLibrary.cpp
//CPP:atomicosproyecto/contadoraux.cpp
#if !defined contadoraux_h
#define contadoraux_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

#include "proyecto/SimulatorLibrary.h"


class contadoraux: public Simulator { 
// Declare the state,
// output variables
// and parameters
double *auxInput;
double sigma;
long int FAOutput;
long int FCOutput;
long int FAROutput;
long int FCROutput;
double winnerBoxWeight;
double winnerBoxDistance;
double missingDistance;
double ret2[3];

// estadisticos
double boxesPC;
double boxesPL;
double arrivals;
double collisions;
double collWinPC;
double collWinPL;
double tie;

//variables de control
double arrival;
double collition;
double collPC;
double continues;


// parameters
char* arrivalsFile;
char* collitionsFile;
char* arrivalsRelationFile;
double cantObjPL;
double cantObjPC;

public:
	contadoraux(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
