#include <random>
#include <algorithm>
#include "Library.h"

//Genera una lista de reales con distribucion Exponencial
std::list<double> genExponentialDistribution(double mean, int qty,unsigned int seed);

//Genera una lista de reales con distribucion Uniforme
std::list<double> genUniformDistribution(double min, double max, int qty,unsigned int seed);

//Ordena la lista de forma intercalada
void interleaved(std::list<double>* a);

//Saca un elemento random de la lista
double popRandomElement(std::list<double>* a);

//Saca el mayor elemento de la lista
//Si no lo encuentra saca un elemento random
double popWeightMayorPcElem(std::list<double>* weights,double enemyWeight);

//Saca el elemento que puede ganarle al peso enemyWeight segun la distancia que este recorrio y el tiempo en que se producira la proxima colision
//Si no lo encuentra saca un elemento random
double pickPossibleWinner(std::list<double>* weights, double enemyWeight, double enemyDistance, double length );

//Cheque si hay pesos que puedan ganarle a enemyWeight
bool checkPossibleWinner(std::list<double> weights, double enemyWeight, double enemyDistance, double length );
