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
    seedWeights = (unsigned int)va_arg(parameters, double);
    seedInterarrivals = (unsigned int)va_arg(parameters, double);

    switch(strategy){
    case 1:
    		weights=genExponentialDistribution(strategy1WeightsMean,quantity,seedWeights);
    		interarrivals=genExponentialDistribution(strategy1InterrarrivalsMean,quantity-1,seedInterarrivals);
    		weights.sort();
    		break;
    case 2:
    		weights=genExponentialDistribution(strategy2WeightsMean,quantity,seedWeights);
    		interarrivals=genExponentialDistribution(strategy2InterrarrivalsMean,quantity-1,seedInterarrivals);
    		weights.sort(std::greater<double>());
    		break;
    case 3:
    		weights=genExponentialDistribution(strategy3WeightsMean,quantity,seedWeights);
    		weights.sort();
    		interleaved(weights);
    		interarrivals=genExponentialDistribution(strategy3InterrarrivalsMean,quantity-1,seedInterarrivals);
    		break;
    default:
    		weights = genUniformDistribution(strategy0WeightsMin,strategy0WeightsMax,quantity,seedWeights);
    		interarrivals=genExponentialDistribution(strategy0InterrarrivalsMean,quantity-1,seedInterarrivals);
    		break;
    }

    sigma=0;
}

double generator::ta(double t) {
//This function returns a double.
    return sigma;
    }
    void generator::dint(double t) {
    	if(!weights.empty()){
    		sigma = interarrivals.back();
    		interarrivals.pop_back();
    	}else{
    		sigma=std::numeric_limits<double>::max();
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
    if(!weights.empty()){
    	aux= weights.back();
    	weights.pop_back();

    	return Event(&aux,0);

    }else{
    	return Event();
    }
}
void generator::exit() {


}
