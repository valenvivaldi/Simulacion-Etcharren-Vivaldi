#include "contador.h"
void contador::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
        va_list parameters;
        va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type
        sigma = std::numeric_limits<double>::max();
}
double contador::ta(double t) {
//This function returns a double.
        return sigma;
}
void contador::dint(double t) {

        sigma = std::numeric_limits<double>::max();
}
void contador::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition

        if(x.port==0) { //port of colitions (arrays of double)
                double* collition =(double*)x.value;
                switch ((int)collition[0]) {
                case 1: colWinJ++;portEmit=0;
                case 0: colTie++;portEmit=1;
                case -1: colWinPc++;portEmit=2;

                }


        }
        if(x.port==1) { //port of arrivals
                std::string msg =*(std::string *)x.value;
                if(msg.compare("LlegoJugador")==0) {
                        arrivalJ++;portEmit=3;
                }else if (msg.compare("LlegoPc")==0) {
                        arrivalPc++;portEmit=4;

                }

        }
        sigma=0;
}
Event contador::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)
switch(portEmit){
case 0:return Event(&colWinJ,portEmit);
case 1:return Event(&colWinPc,portEmit);
case 2:return Event(&colTie,portEmit);
case 3:return Event(&arrivalPc,portEmit);
case 4:return Event(&arrivalJ,portEmit);
}

        return Event();
}
void contador::exit() {
//Code executed at the end of the simulation.
        printLog("Colisiones ganadas por Jugador: %d \n",colWinJ);
        printLog("Colisiones ganadas por Pc: %d \n",colWinPc);
        printLog("Colisiones empatadas: %d \n",colTie);
        printLog("Arrivos Jugador: %d \n",arrivalJ);
        printLog("Arrivos Pc: %d \n",arrivalPc);
}
