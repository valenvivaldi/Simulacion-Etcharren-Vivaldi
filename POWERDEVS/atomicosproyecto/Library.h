#ifndef SIMLIB_H
#define SIMLIB_H

#include <iostream>
#include <list>
#include <limits>
#include "simulator.h"
#include "event.h"
#include "stdarg.h"

double calcularsigma(std::list< std::pair<double,double> >colaJug  , std::list< std::pair<double,double> > colaPc , double time, double l, double vc);

double pesoNuevo(std::list< std::pair<double,double> > colaVenc , std::list< std::pair<double,double> > colaPerd , double time,double vc);

double potencia(std::list< std::pair<double,double> > cola , double time,double vc);
double potencia(double weigth, double distance);

double dist(std::list< std::pair<double,double> > cola , double time,double vc);

void mostrarCola (std::list< std::pair<double,double> > cola);

#endif
