#include "cinta.h"
void cinta::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
        va_list parameters;
        va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//	%Type% is the parameter type

//getting parameters
        l = va_arg(parameters, int);
        vc = va_arg(parameters, int);
}
double cinta::ta(double t) {
//This function returns a double.
        return sigma;
}
void cinta::dint(double t) {
        if((!(cJ.empty()) && !(cPc.empty()) && potencia(cJ,time) > potencia(cPc,time))) {//gana colision jugador
                time = time + sigma;                  //se actualiza el tiempo de ejecucion
                cJ.front()[0] = pesoNuevo(cJ,cPc,time);  //se actualiza el peso del objeto de la cabeza de la cola ganadora
                cPc.pop_front();                                 //se saca el objeto que perdio la colision
                sigma = calcularsigma(cJ,cPc,time);            //se calcula el nuevo sigma

        }else if(!(cJ.empty()) && !(cPc.empty()) && potencia(cJ,time) > potencia(cPc,time))   {//gana colision pc
                time = time + sigma;                  //se actualiza el tiempo de ejecucion
                cJ.pop_front();                        //se saca el objeto que perdio la colision
                cPc.front()[0] = pesoNuevo(cPc,cJ,time); //se actualiza el peso del objeto de la cabeza de la cola ganadora
                sigma = calcularsigma(cJ,cPc,time); //se calcula el nuevo sigma


        }else if (!(cJ.empty()) && !(cPc.empty()) && potencia(cJ,time) == potencia(cPc,time)) { //empate colision
                time = time + sigma;                  //se actualiza el tiempo de ejecucion
                cJ.pop_front();                         //se saca el objeto que empate la colision
                cPc.pop_front();//se saca el objeto que empate la colision
                sigma = calcularsigma(cJ,cPc,time);


        }else if (!(cJ.empty()) && (cPc.empty()))   {//llega objeto jugador al final de la cinta
                time = time + sigma;                  //se actualiza el tiempo de ejecucion
                cJ.pop_front();                         //se saca el objeto que llego al final de la cinta
                sigma = calcularsigma(cJ,cPc,time);


        }else if ((cJ.empty()) && !(cPc.empty()))   {//llega objeto pc al final de la cinta
                time = time + sigma;                              //se actualiza el time de ejecucion
                cPc.pop_front();                                  //se saca el objeto que llego al final de la cinta
                sigma = calcularsigma(cJ,cPc,time);            //se calcula el nuevo sigma

        }else{
        }

}
void cinta::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the time elapsed since last transition
        if (x.port==1) {
                time +=e;
                double box[2];
                box[0]=double(x.value);
                box[1]=time;
                cJ.push_back(box);
                sigma=calcularsigma(cJ,cPc,time);
        }
        else if(x.port==0) {
                time +=e;
                double box[2];
                box[0]=double(x.value);
                box[1]=time;
                cPc.push_back(box);
                sigma=calcularsigma(cJ,cPc,time);
        }

}
Event cinta::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)
        int value1[3]; //stores the value to return in the event of a collision (only sent through port 1)
        std::string value2;//stores the value to return in the case that the end of the tape is reached (only sent through port 2)
        if(!(cJ.empty()) && !(cPc.empty()) && potencia(cJ,time+sigma) > potencia(cPc,time+sigma)) { //gano colision jugador
                value1[0]=1;
                value1[1]=pesoNuevo(cJ,cPc,time+sigma);
                value1[2]=dist(cJ,time+sigma);
                return Event(&value1,1);
        }else if(!(cJ.empty()) && !(cPc.empty()) && potencia(cJ,time+sigma) > potencia(cPc,time+sigma)) { //gano colision pc
                value1[0]=-1;
                value1[1]=pesoNuevo(cJ,cPc,time+sigma);
                value1[2]=dist(cJ,time+sigma);
                return Event(&value1,1);
        }else if(!(cJ.empty()) && !(cPc.empty()) && potencia(cJ,time+sigma) > potencia(cPc,time+sigma)) { //empate colision
                value1[0]=0;
                value1[1]=0;
                value1[2]=0;
                return Event(&value1,1);
        }else if (!(cJ.empty()) && (cPc.empty())) { //llego al final de la cinta un objeto de jugador
                value2="LlegoJugador";
                return Event(&value2,2);
        }else if ((cJ.empty()) && !(cPc.empty())) { //llego al final de la cinta un objeto de pc
                value2="LlegoPc";
                return Event(&value2,2);
        }

        return Event();
}
void cinta::exit() {
//Code executed at the end of the simulation.

}