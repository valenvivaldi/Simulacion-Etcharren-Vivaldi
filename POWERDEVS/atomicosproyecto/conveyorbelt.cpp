#include "conveyorbelt.h"
void conveyorbelt::init(double t,...) {
//The 'parameters' variable contains the parameters transferred from the editor.
    va_list parameters;
    va_start(parameters,t);
//To get a parameter: %Name% = va_arg(parameters,%Type%)
//where:
//      %Name% is the parameter name
//  %Type% is the parameter type

//getting parameters
    l = va_arg(parameters, double);
    vc = va_arg(parameters, double);
    sigma=calculateSigma(cJ,cPc,t,l,vc);// sigma queda en infinito por estar las colas vacias
    value[0]=0;
    value[1]=0;
    value[2]=0;
//cJ={};
//cPc={};
}

double conveyorbelt::ta(double t) {
//This function returns a double.
    return sigma;
}

void conveyorbelt::dint(double t) {
    if (!cJ.empty() && !cPc.empty()){   //hubo una colision
        if (power(cJ,t,vc) > power(cPc,t,vc)){      //gana colision player
            cJ.front().first = newWeight(cJ,cPc,t,vc);       //se actualiza el peso del objeto de la cabeza de la cola ganadora
            cPc.pop_front();
        }else if (power(cJ,t,vc) < power(cPc,t,vc)){ //gana colision Pc
            cPc.front().first = newWeight(cPc,cJ,t,vc);      //se actualiza el peso del objeto de la cabeza de la cola ganadora
            cJ.pop_front();                                     //se saca el objeto que perdio la colision
        }else{                                                  //empate
            cJ.pop_front();                                     //se saca el objeto que empate la colision
            cPc.pop_front();                                    //se saca el objeto que empate la colision
        }
    }else if (!cJ.empty() && cPc.empty()){                      //llego un objeto jugador al final de la cinta
        cJ.pop_front();                                         //se saca el objeto que llego al final de la cinta
    }else if (cJ.empty() && !cPc.empty())   {                   //llega objeto pc al final de la cinta
        cPc.pop_front();                                        //se saca el objeto que llego al final de la cinta
    }
    sigma = calculateSigma(cJ,cPc,t,l,vc);                    //se calcula el nuevo sigma

}

void conveyorbelt::dext(Event x, double t) {
//The input event is in the 'x' variable.
//where:
//     'x.value' is the value (pointer to void)
//     'x.port' is the port number
//     'e' is the t elapsed since last transition
    std::pair<double,double> box (*((double*)x.value),t);
    if (x.port==1) {//entra caja jugador
        cJ.push_back(box);
    }
    else if(x.port==0){//entra caja pc
        cPc.push_back(box);
    }
    sigma=calculateSigma(cJ,cPc,t,l,vc);
}

Event conveyorbelt::lambda(double t) {
//This function returns an Event:
//     Event(%&Value%, %NroPort%)
//where:
//     %&Value% points to the variable which contains the value.
//     %NroPort% is the port number (from 0 to n-1)
    if(!(cJ.empty()) && !(cPc.empty()) && power(cJ,t,vc) > power(cPc,t,vc)) { //gano colision jugador
        //printLog("Colision! gano jugador \n");
        value[0]=1;
        value[1]=newWeight(cJ,cPc,t,vc);
        value[2]=dist(cJ,t,vc);
        return Event(&value,0);
    }else if(!(cJ.empty()) && !(cPc.empty()) && power(cJ,t,vc) < power(cPc,t,vc)) { //gano colision pc
        //printLog("Colision! gano PC  \n");
        value[0]=-1;
        value[1]=newWeight(cPc,cJ,t,vc);
        value[2]=dist(cPc,t,vc);
        return Event(&value,0);
    }else if(!(cJ.empty()) && !(cPc.empty()) && power(cJ,t,vc) == power(cPc,t,vc)) { //empate colision
        //printLog("Colision Ouput! Empate \n");
        // otra mejora a realizar
        value[0]=0;
        value[1]=weightSecondElement(cPc);
        value[2]=distSecond(cPc,t,vc);

        return Event(&value,0);
    }else if (!cJ.empty() && cPc.empty()) { //llego al final de la cinta un objeto de jugador
        //printLog("llego un elemento de Jugador \n");
        value[0]=1;
        value[1]=0;
        value[2]=0;
        return Event(&value,1);
    }else if (cJ.empty() && !cPc.empty()) { //llego al final de la cinta un objeto de pc
        //printLog("llrgo un elemento de PC \n");
        value[0]=0;
        value[1]=weightSecondElement(cPc);
        value[2]=distSecond(cPc,t,vc);
        return Event(&value,1);
    }
    return Event();
}

void conveyorbelt::exit() {
//Code executed at the end of the simulation.
}
