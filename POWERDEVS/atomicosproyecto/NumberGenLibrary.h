//#include <iostream>
//#include <list>
#include <random>
#include <algorithm>
//#include "simulator.h"
//#include "event.h"
//#include "stdarg.h"
#include "Library.h"

std::list<double> genExponentialDistribution(double mean, int qty,unsigned int seed);
std::list<double> genUniformDistribution(double min, double max, int qty,unsigned int seed);
std::list<double> interleaved(std::list<double> a);
double popRandomElement(std::list<double>* a);

double pickPossibleWinner(std::list<double>* weights, double enemyWeight, double enemyDistance, double length );
bool checkPossibleWinner(std::list<double>* weights, double enemyWeight, double enemyDistance, double length );
