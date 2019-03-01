#include "simplegenerator.h"
void simplegenerator::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type
sigma=0;
}
double simplegenerator::ta(double t) {
//This function returns a double.
return sigma;
}
void simplegenerator::dint(double t) {
sigma = 10;
}
void simplegenerator::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition

}
Event simplegenerator::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)

aux=3;
return Event(&aux,0);
}
void simplegenerator::exit() {
//Code executed at the end of the simulation.

}
