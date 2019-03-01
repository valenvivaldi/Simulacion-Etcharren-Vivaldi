#include "Library.h"

double calcularsigma(std::list< std::pair<double,double> >colaJug  , std::list< std::pair<double,double> > colaPc , double time, double l, double vc){
        if ((colaJug.empty()) && (colaPc.empty())) { //colas vacias
          return  std::numeric_limits<double>::max();
        }else if(!(colaJug.empty())&& (colaPc.empty())) { //cola pc vacia
          return l - dist(colaJug,time,vc) / vc;
        }else if ((colaJug.empty()) && !(colaPc.empty())) {//cola jugador vacia
          return l - dist(colaJug,time,vc) / vc;
        }else if(!(colaJug.empty()) && !(colaPc.empty())) { //ninguna cola vacia
          return l - (dist(colaJug,time,vc) + dist(colaPc,time,vc) / (2*vc));
        }
};

double pesoNuevo(std::list< std::pair<double,double> > colaVenc , std::list< std::pair<double,double> > colaPerd , double time,double vc){
return colaVenc.front().first * ((colaPerd.front().first * dist(colaPerd,time,vc)) / (colaVenc.front().first * dist(colaVenc,time,vc)));
};

double potencia(std::list< std::pair<double,double> > cola , double time,double vc){
        return cola.front().first * dist(cola,time,vc);
};

double dist(std::list< std::pair<double,double> > cola , double time,double vc){
        return (time-cola.front().second)*vc;
};
