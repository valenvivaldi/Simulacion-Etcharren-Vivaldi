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
			weights.sort();
			break;
	case 5:
			weights=genExponentialDistribution(7.5,quantity);		
			weights.sort(std::greater<double>());
			break;
	case 6:
			weights=genExponentialDistribution(7.5,quantity);
			weights.sort();
			break;
	case 7:
			weights=genExponentialDistribution(7.5,quantity);
			weights.sort();
			break;

	default:
			weights = genUniformDistribution(5,10,quantity);
			interarrivals=genExponentialDistribution(10,quantity-1);
			break;
	}
	sigma=0;

	pickwinner=0;

	printLog("TERMINO INIT\n");
}
double feedbackgenerator::ta(double t) {
//This function returns a double.
	return sigma;
}
void feedbackgenerator::dint(double t) {
	if(weights.size()>0){
		sigma=std::numeric_limits<double>::max();


	}else{
		sigma=std::numeric_limits<double>::max();
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
				if(strategy==6 && !checkPossibleWinner(&weights,weightOpponent,distOpponent,length)){
					sigma=std::numeric_limits<double>::max();
				}else{
					sigma=0;
					pickwinner=1;
				}
				
				weightOpponent=col[1];
				distOpponent=col[2];
				break;
			default: //ganamos la colision
				sigma=std::numeric_limits<double>::max();
		}
	}
	if (x.port==1){ //puerto de llegadas
		if(*(double*)x.value){
			printLog("hubo llegada nuestra! mandamos un aleatorio quedan \n");
			sigma=0;
		}else{ 
			printLog("hubo llegada de pc!\n");
		
		}
		
	}
	if(weights.size()==0){sigma=std::numeric_limits<double>::max();}
}
Event feedbackgenerator::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)
	if(weights.size()>0){
		if(pickwinner){
			if(strategy==4){
				if(checkPossibleWinner(&weights,weightOpponent,distOpponent,length)){
					aux=pickPossibleWinner(&weights,weightOpponent,distOpponent,length);

				}else{
					aux=popRandomElement(&weights);
				}
			
			}
			if(strategy==5){
				aux=weights.front();
				weights.pop_front();
			}
			if(strategy==6){
				aux=pickPossibleWinner(&weights,weightOpponent,distOpponent,length);
			}
			if(strategy==7){
				aux=pickPossibleWinner(&weights,weightOpponent,distOpponent,length);
			}
			pickwinner=0;
		}else{
			aux=popRandomElement(&weights);
		}
		return Event(&aux,0);




	}
	else{
		return Event();
	}

}
void feedbackgenerator::exit() {

}
