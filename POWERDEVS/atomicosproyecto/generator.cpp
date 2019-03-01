#include "generator.h"
void generator::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type
strategy =(int) va_arg(parameters, double);
quantity = (int)va_arg(parameters, double);

switch(strategy){
case 1:
		weights=genExponentialDistribution(7.5,quantity);
		interarrivals=genExponentialDistribution(10,quantity-1);
		//std::sort(weights.begin(),weights.end());
		break;
default:
		weights = genUniformDistribution(6,8,quantity);
		interarrivals=genExponentialDistribution(10,quantity-1);
		break;
}

sigma=0;
dispatched=0;


}
double generator::ta(double t) {
//This function returns a double.
return sigma;
}
void generator::dint(double t) {
if(dispatched < quantity){
sigma = interarrivals.back();
interarrivals.pop_back();
}else{
sigma=10e10;
 //exit();
}

}
void generator::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition

}
Event generator::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)
if(dispatched < quantity){
	aux= weights.back();
	weights.pop_back();
	dispatched++;
	return Event(&aux,0);
}
else{
	//exit();
}

}
void generator::exit() {


}
