#include "contadoraux.h"
void contadoraux::init(double t,...) {
	va_list parameters;
	va_start(parameters,t);	
	//printLog("Init (contadoraux)\n");
	cantObjPL = 100;
	cantObjPC = 100;
	sigma = std::numeric_limits<double>::max();
	// Estadisticos
	boxesPC = 0;
	boxesPL = 0;
	arrivals = 0;
	collisions = 0;
	collWinPC = 0;
	collWinPL = 0;
	tie = 0;
	// Variables de control
	arrival = 0;
	collition = 0;
	collPC = 0;
	continues = 0;
	//Inicializacion de ficheros	
}

double contadoraux::ta(double t) {
	return sigma;
}

void contadoraux::dint(double t) {
	if (continues) {
		sigma = 0;
		continues = 0;
	} else {
		sigma = std::numeric_limits<double>::max();
		continues = 0;
	}
}

void contadoraux::dext(Event x, double t) {
	auxInput = (double*) x.value;
	//printLog("Dext (contadoraux) --> ");
	if (x.port == 0){
		// Llegada
		arrival = 1;
		arrivals = arrivals + 1;
		//printLog("VIENDO %f\n", *auxInput);
		if(*auxInput == 1){
			//printLog("Player's object arrive.\n");
			boxesPL = boxesPL + 1;
		} 
		if(*auxInput == 2){
			//printLog("Computer's object arrive.\n");
			boxesPC = boxesPC + 1;
		}	
	} else {
		// Colision
		collition = 1;
		collisions = collisions + 1;
		if(auxInput[0] == -1){
			//PL Win
			collWinPL = collWinPL +1;
			//printLog("Collition: Player Wins\n");
		}
		if(auxInput[0] == -2){
			//Tie
			tie = tie + 1;
			//printLog("Collition: Tie\n");
		}
		if(auxInput[0] >= 0){
			//PC Win
			collWinPC = collWinPC +1;
			collPC = 1;
			winnerBoxWeight = auxInput[0];
			winnerBoxDistance = auxInput[1];
			missingDistance = auxInput[2];
			//printLog("Collition: Computer Wins\n");
		} 
	}
	sigma = 0;
	continues = 1;
}
Event contadoraux::lambda(double t) {
	if (continues) {
		//printLog("\nLambda (contadoraux) --> ");
		if (arrival){
			arrival = 0;
			//printLog("Arrival at %g, %g pl's boxes and %g pc's boxes\n\n",t,boxesPL,boxesPC);
			//double ret = 0;
			ret2[0] = 0;
			return Event(&ret2,0);
		}		
		if (collition){
			collition = 0;
			//printLog("Collition at %g, %g pl's collitions, %g pc's collitions and %g ties\n\n",t,collWinPL,collWinPC,tie);
			return Event();
		}
	} else {
		if (collPC){
			collPC = 0;
			ret2[0] = winnerBoxWeight;
			ret2[1] = winnerBoxDistance;
			ret2[2] = missingDistance;
			return Event(&ret2,0);
		} else {
			return Event();
		}
	}
}
void contadoraux::exit() {

	printLog("\n------------------------- Simulation End -------------------------\n");
	printLog("		Total Arrivals: %g\n",arrivals);
	printLog("				Arrivals PC: %g\n",boxesPC);
	printLog("				Arrivals PL: %g\n",boxesPL);
	printLog("		Total Collitions: %g\n",collisions);
	printLog("				Collitions PC Win: %g\n",collWinPC);
	printLog("				Collitions PL Win: %g\n",collWinPL);
	printLog("				Collitions Tie: %g\n",tie);
	printLog("--------------------------------------------------------------------\n");
}
