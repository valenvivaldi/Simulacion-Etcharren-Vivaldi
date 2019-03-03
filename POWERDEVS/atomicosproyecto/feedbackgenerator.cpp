#include "feedbackgenerator.h"
void feedbackgenerator::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
va_list parameters;
va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type
strategy =(int) va_arg(parameters, double);
quantity = (int)va_arg(parameters, double);
length = (int)va_arg(parameters, double);

switch(strategy){
case 4:
		weights=genExponentialDistribution(7.5,quantity);
		weights.sort(std::greater<double>());

case 5:
		weights=genExponentialDistribution(7.5,quantity);		
		weights.sort(std::greater<double>());

case 6:
		weights=genExponentialDistribution(7.5,quantity);

default:
		weights = genUniformDistribution(6,8,quantity);
		interarrivals=genExponentialDistribution(10,quantity-1);
		break;
}

sigma=0;
dispatched=0;
pickwinner=0;

printLog("TERMINO INIT\n");
}
double feedbackgenerator::ta(double t) {
//This function returns a double.
return sigma;
}
void feedbackgenerator::dint(double t) {
if(dispatched < quantity){
	sigma=10e10;


}else{
	sigma=10e10;
 //exit();
}

}
void feedbackgenerator::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition

	printLog("delta ext %d \n",x.port);
if(x.port==0){ //puerto de colisiones

	double* col =(double*)x.value;
	switch ((int)col[0]){
		case 0: //empatamos la colision
			sigma=0;
			break;
		case -1://perdemos la colision
			sigma=0;
			pickwinner=1;
			weightOpponent=col[1];
			distOpponent=col[2];
			break;
		default: //ganamos la colision
			sigma=10e10;
	}
}


if (x.port==1){ //puerto de llegadas
	if(*(double*)x.value){
		printLog("hubo llegada nuestra! mandamos un aleatorio quedan \n");
	
		sigma=0;
	}else{ 
		printLog("hubo llegada de pc! significa que no tenemos mas pesos que mandar\n");
	sigma=10e10;
	}
	
}

if(weights.size()==0){sigma=10e10;}
}
Event feedbackgenerator::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)
if(dispatched < quantity && weights.size()>0){
	if(pickwinner){
		if(strategy==4){
			aux=pickPossibleWinner(&weights,weightOpponent,distOpponent,length);
		}
		if(strategy==5){
			aux=weights.front();
			weights.pop_front();
		}
			
	}else{
		aux=popRandomElement(&weights);
	}
	dispatched++;
	return Event(&aux,0);




}
else{
	//exit();
}

}
void feedbackgenerator::exit() {


}
