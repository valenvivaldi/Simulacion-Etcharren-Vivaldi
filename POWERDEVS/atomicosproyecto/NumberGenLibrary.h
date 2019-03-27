#include <random>
#include <algorithm>
#include "Library.h"

//Genera una lista de reales con distribucion Exponencial
// PARAMETROS:
//mean: media de los valores generados
//qty: cantidad de valores a generar
//seed: semillas de la generacion(si es 0 genera una aleatoria)
std::list<double> genExponentialDistribution(double mean, int qty,unsigned int seed);

//Genera una lista de reales con distribucion Uniforme
// PARAMETROS:
// min: valor minimo de los valores a generar
// max: valor maximo de los valores a generar
//qty: cantidad de valores a generar
//seed: semillas de la generacion(si es 0 genera una aleatoria)
std::list<double> genUniformDistribution(double min, double max, int qty,unsigned int seed);

//Ordena la lista de forma intercalada
// PARAMETROS:
//a: puntero a la lista
void interleaved(std::list<double>* a);

//Saca un elemento random de la lista  de pesos y lo retorna
// PARAMETROS:
//a: puntero a la lista
double popRandomElement(std::list<double>* a);

//Saca el minimo peso, de la lista, que supera a enemyWeight
//Si no lo encuentra saca un elemento random
// PARAMETROS:
//weights: puntero a la lista de pesos
//enemyWeight: peso de la caja que se quiere superar
double popWeightMayorPcElem(std::list<double>* weights,double enemyWeight);

//Saca el elemento que puede ganarle al peso enemyWeight segun la distancia que este recorrio y el tiempo en que se producira la proxima colision
//Si no lo encuentra saca un elemento random
// PARAMETROS:
//weights: puntero a la lista
//enemyWeight: peso de la caja que se quiere derrotar
//enemyDistance: distancia que lleva recorrida el enemigo
//length: largo total de la cinta
double pickPossibleWinner(std::list<double>* weights, double enemyWeight, double enemyDistance, double length );

//Cheque si hay pesos que puedan ganarle a enemyWeight
bool checkPossibleWinner(std::list<double> weights, double enemyWeight, double enemyDistance, double length );
