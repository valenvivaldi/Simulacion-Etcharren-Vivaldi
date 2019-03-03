#include <iostream>
#include <list>
#include <random>
#include <algorithm>
#include "simulator.h"
#include "event.h"
#include "stdarg.h"

std::list<double> genExponentialDistribution(double mean, int qty);
std::list<double> genUniformDistribution(double min, double max, int qty);
std::list<double> interleaved(std::list<double> a);
double popRandomElement(std::list<double>* a);

double pickPossibleWinner(std::list<double>* weights, double winner, double distance);