#ifndef SIMLIB_H
#define SIMLIB_H

#include <iostream>
#include <list>
#include <limits>
#include "simulator.h"
#include "event.h"
#include "stdarg.h"

//Calcula el tiempo en que se producira la proxima colision
double calculateSigma(std::list< std::pair<double,double> >playerQueue  , std::list< std::pair<double,double> > pcQueue , double time, double l, double vc);

//Calcula el peso nuevo del Objeto vencedor
double newWeight(std::list< std::pair<double,double> > winnerQueue , std::list< std::pair<double,double> > loserQueue , double time,double vc);

//Calcula la potencia del primer elemento de una cola de cajas segun su tiempo de arribo, peso, tiempo de ejecucion y velocida de la Cinta
double power(std::list< std::pair<double,double> > queue , double time,double vc);

//Calcula la potencia de una caja segun su peso y distancia recorrida
double power(double weigth, double distance);

//Calcula la distancia rrecorrida del primer elemento de la cola de cajas
double dist(std::list< std::pair<double,double> > queue , double time,double vc);

//Imprime los pesos de una cola de cajas
void showQueue (std::list< std::pair<double,double> > queue);

//Devuelve el peso del segundo elemento de una cola de cajas
double weightSecondElement(std::list< std::pair<double,double> > queue);

//Calcula la distancia en que se encuentra el segundo elemento de la cola de cajas
double distSecond(std::list< std::pair<double,double> > queue , double time,double vc);


#endif
