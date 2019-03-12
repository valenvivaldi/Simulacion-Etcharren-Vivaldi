//FLAGS:-std=c++11
//CPP:atomicosproyecto/NumberGenLibrary.cpp
//CPP:atomicosproyecto/generator.cpp
//CPP:atomicosproyecto/feedbackgenerator.cpp
#if !defined feedbackgenerator_h
#define feedbackgenerator_h

#include "simulator.h"
#include "event.h"
#include "stdarg.h"

#include "atomicosproyecto/NumberGenLibrary.h"


class feedbackgenerator: public Simulator { 
// Declare the state,
// output variables
// and parameters

//parameters
int strategy;
int quantity;
int length;

//state
std::list<double> weights;
std::list<double> interarrivals;

double sigma;
double aux;

//indica si el proximos despache
// sera un posible ganador(1)
// o uno aleatorio  (0)
bool pickwinner;
double weightOpponent;
double distOpponent;
public:
	feedbackgenerator(const char *n): Simulator(n) {};
	void init(double, ...);
	double ta(double t);
	void dint(double);
	void dext(Event , double );
	Event lambda(double);
	void exit();
};
#endif
