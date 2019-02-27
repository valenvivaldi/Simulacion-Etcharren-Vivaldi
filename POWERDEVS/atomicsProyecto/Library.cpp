#include <Library.h>

double calcularsigma(std::List<double[]> colaJug, std::List<double[]> colaPc,double time){
        if ((colaJug.empty()) && (colaPc.empty())) { //colas vacias
          return INFINITE;
        }else if(!(colaJug.empty())&& (colaPc.empty())) { //cola pc vacia
          return l - dist(colaJug,time) / VC
        }else if ((colaJug.empty()) && !(colaPc.empty())) {//cola jugador vacia
          return l - dist(colaJug,time) / VC
        }else if(!(colaJug.empty()) && !(colaPc.empty())) { //ninguna cola vacia
          return l - (dist(colaJug,time) + dist(colaPc,time) / (2*VC))
        }
};

double pesoNuevo(std::List<double[]> colaVenc, std::List<double[]> colaPerd, double time){
return colaVenc.front()[0] * ((colaPerd.front()[0] * dist(colaPerd,time)) / (colaVenc.front()[0] * dist(colaVenc,time)));
};

double potencia(std::List<double[]> cola,double time){
        return cola.front()[0]*dist(cola,time);
};

double dist(std::List<double[]> cola,double time){
        return (time-cola.front()[1])*vc;
};
