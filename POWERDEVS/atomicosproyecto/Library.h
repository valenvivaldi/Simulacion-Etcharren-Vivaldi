#ifndef SIMLIB_H
#define SIMLIB_H

#include <iostream>
#include <list>
#include <limits>
#include "simulator.h"
#include "event.h"
#include "stdarg.h"

//Calcula el tiempo en que se producira la proxima colision,
// devolviendo en cuanto tiempo van a colisionar los primeros elementos de ambas colas
//teniendo en cuenta el largo de la cinta, y la velocidad
//PARAMETROS:
// playerQueue: cola del jugador human
// pcQueue: cola del jugador pc
//l: largo de la cola
// time: tiempo en el que ocurre la colision
// vc:velocidad de la cola
double calculateSigma(std::list< std::pair<double,double> >playerQueue  , std::list< std::pair<double,double> > pcQueue , double time, double l, double vc);

//Calcula el peso nuevo del Objeto vencedor, a partir de los
// PARAMETROS:
// winnerQueue: cola del jugador que gano la colision
// loserQueue: cola del jugador que perdio de la colisiones
// time: tiempo en el que ocurre la colision
// vc:velocidad de la cola
double newWeight(std::list< std::pair<double,double> > winnerQueue , std::list< std::pair<double,double> > loserQueue , double time,double vc);

//Calcula la potencia del primer elemento de una cola de cajas segun su tiempo de arribo, peso, tiempo de ejecucion y velocida de la Cinta
// PARAMETROS:
// queue: cola
// time: tiempo
// vc:velocidad de la cola
double power(std::list< std::pair<double,double> > queue , double time,double vc);

//Calcula la potencia de una caja segun su peso y distancia recorrida
// PARAMETROS:
// weigth: peso de la cajas
// distance: distancia que lleva recorrida la caja
double power(double weigth, double distance);

//Calcula la distancia rrecorrida del primer elemento de la cola de cajas
// PARAMETROS:
// queue: cola del jugador
// time: tiempo en el que ocurre la colision
// vc:velocidad de la cola
double dist(std::list< std::pair<double,double> > queue , double time,double vc);

//Imprime los pesos de una cola de cajas
// PARAMETROS:
// queue: cola de pesos

void showQueue (std::list< std::pair<double,double> > queue);

//Devuelve el peso del segundo elemento de una cola de cajas
// PARAMETROS:
// queue: cola del jugador que gano la colision
double weightSecondElement(std::list< std::pair<double,double> > queue);

//Calcula la distancia en que se encuentra el segundo elemento de la cola de cajas
// PARAMETROS:
// queue: cola del jugador que gano la colision

double distSecond(std::list< std::pair<double,double> > queue , double time,double vc);


#endif
