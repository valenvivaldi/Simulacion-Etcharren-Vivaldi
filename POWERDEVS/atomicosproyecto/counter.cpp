#include "counter.h"
void counter::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
    va_list parameters;
    va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type
    sigma = std::numeric_limits<double>::max();
	colWinJ=0;
	colTie=0;
	colWinPc=0;
	arrivalPc=0;
	arrivalJ=0;
}
double counter::ta(double t) {
//This function returns a double.
    return sigma;
}
void counter::dint(double t) {
    sigma = std::numeric_limits<double>::max();
}
void counter::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition
    double* value =(double*)x.value;
    if(x.port==0) { //port of colitions (arrays of double)
    //double* collition =(double*)x.value;
        switch ((int)value[0]) {
            case 1:
                colWinJ++;
                portEmit=0;
                break;
            case 0:
                colTie++;
                portEmit=1;
                break;
        	case -1:
                colWinPc++;
                portEmit=2;
                break;
        }
    }
    if(x.port==1) { //port of arrivals
        if(*value==1) {
            arrivalJ++;
			portEmit=4;
        }else if (*value==0) {
            arrivalPc++;
			portEmit=3;
        }
    }
    sigma=0;
}
Event counter::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)
    switch(portEmit){
        case 0:
            aux = colWinJ;
            return Event(&aux,portEmit);
            break;
        case 1:
            aux = colTie;
            return Event(&aux,portEmit);
            break;
        case 2:
            aux = colWinPc;
            return Event(&aux,portEmit);
            break;
        case 3:
            aux = arrivalPc;
            return Event(&aux,portEmit);
            break;
        case 4:
            aux = arrivalJ;
            return Event(&aux,portEmit);
            break;
    }
}
void counter::exit() {
//Code executed at the end of the simulation.
    printLog("--------------Resultados simulacion----------");
    printLog("---------------------------------------------");
    printLog("---------------------------------------------");
    printLog("---------------------------------------------\n");
    printLog("NUESTRO Colisiones ganadas por Jugador: %d \n",colWinJ);
    printLog("NUESTRO Colisiones ganadas por Pc: %d \n",colWinPc);
    printLog("NUESTRO Colisiones empatadas: %d \n",colTie);
    printLog("NUESTRO Arrivos Jugador: %d \n",arrivalJ);
    printLog("NUESTRO Arrivos Pc: %d \n",arrivalPc);
    printLog("---------------------------------------------");
    printLog("---------------------------------------------");
    printLog("---------------------------------------------");

}
