#include <Library.h>

double calcularsigma(std::List<std::pair<double,double> >colaJug, std::List<std::pair<double,double> >colaPc,double time){
        if ((colaJug.empty()) && (colaPc.empty())) { //colas vacias
          return  std::numeric_limits<double>::max();
        }else if(!(colaJug.empty())&& (colaPc.empty())) { //cola pc vacia
          return l - dist(colaJug,time) / VC
        }else if ((colaJug.empty()) && !(colaPc.empty())) {//cola jugador vacia
          return l - dist(colaJug,time) / VC
        }else if(!(colaJug.empty()) && !(colaPc.empty())) { //ninguna cola vacia
          return l - (dist(colaJug,time) + dist(colaPc,time) / (2*VC))
        }
};

double pesoNuevo(std::List<std::pair<double,double> >colaVenc, std::List<std::pair<double,double> >colaPerd, double time){
return colaVenc.front().first * ((colaPerd.front().first * dist(colaPerd,time)) / (colaVenc.front().first * dist(colaVenc,time)));
};

double potencia(std::List<std::pair<double,double> >cola,double time){
        return cola.front().first * dist(cola,time);
};

double dist(std::List<std::pair<double,double> >cola,double time){
        return (time-cola.front().second)*vc;
};
