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
	seed = (unsigned int)va_arg(parameters, double);

	if(seed == 0){
        std::random_device rd;
        srand(rd());
    }else{
        srand(seed);
    }

	switch(strategy){
	case 4:
			weights=genExponentialDistribution(strategy4WeightsMean,quantity,seed);
			weights.sort();
			break;
	case 5:
			weights=genExponentialDistribution(strategy5WeightsMean,quantity,seed);
			weights.sort(std::greater<double>());
			break;
	case 6:
			weights=genExponentialDistribution(strategy6WeightsMean,quantity,seed);
			weights.sort();
			break;
	case 7:
			weights=genExponentialDistribution(strategy7WeightsMean,quantity,seed);
			weights.sort();
			break;

	default:
			weights = genUniformDistribution(strategy0WeightsMin,strategy0WeightsMax,quantity,seed);
			interarrivals=genExponentialDistribution(strategy0InterrarrivalsMean,quantity-1,seed);
			break;
	}
	sigma=0;
	pickwinner=0;

	//printLog("TERMINO INIT\n");
}
double feedbackgenerator::ta(double t) {
//This function returns a double.
	return sigma;
}
void feedbackgenerator::dint(double t) {
	sigma=std::numeric_limits<double>::max();
	//exit();
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
			//printLog("hubo llegada nuestra! mandamos un aleatorio quedan \n");
			sigma=0;
		}else{
			if ((strategy==6 && checkPossibleWinner(&weights,weightOpponent,distOpponent,length))){
				sigma = 0;
				pickwinner = 1;
			}
			//printLog("hubo llegada de pc!\n");

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
