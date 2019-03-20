#ifndef SIMLIB_H
#define SIMLIB_H

#include <iostream>
#include <list>
#include <limits>
#include "simulator.h"
#include "event.h"
#include "stdarg.h"

double calculateSigma(std::list< std::pair<double,double> >playerQueue  , std::list< std::pair<double,double> > pcQueue , double time, double l, double vc);

double newWeight(std::list< std::pair<double,double> > winnerQueue , std::list< std::pair<double,double> > loserQueue , double time,double vc);

double power(std::list< std::pair<double,double> > queue , double time,double vc);
double power(double weigth, double distance);

double dist(std::list< std::pair<double,double> > queue , double time,double vc);

void showQueue (std::list< std::pair<double,double> > queue);
double weightSecondElement(std::list< std::pair<double,double> > queue);
double distSecond(std::list< std::pair<double,double> > queue , double time,double vc);


#endif
