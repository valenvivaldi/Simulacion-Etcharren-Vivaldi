#include "Library.h"

double calcularsigma(std::list< std::pair<double,double> >colaJug  , std::list< std::pair<double,double> > colaPc , double time, double l, double vc){
        printLog("EJECUTA PRINT LOG\n");
        
        printLog("cJ:{");
			std::pair<double,double> aux;
			for (std::list<std::pair<double,double> >::iterator it=colaJug .begin(); it != colaJug .end(); ++it){
				aux=*it;
				printLog("%g,",aux.first);
			
			}				
			printLog("}\n");

			printLog("cPc:{");
			
			for (std::list<std::pair<double,double> >::iterator it=colaPc.begin(); it != colaPc.end(); ++it){
				aux=*it;
				printLog("%g,",aux.first);
			
			}				
			printLog("}\n");
        
        
        
        
        
        
        
        
        if ((colaJug.empty()) && (colaPc.empty())) { //colas vacias
		printLog("colas vacias!\n");
          return  std::numeric_limits<double>::max();
        }else if(!(colaJug.empty())&& (colaPc.empty())) { //cola pc vacia
		printLog("pc  vacia!\n");
          return (l - dist(colaJug,time,vc) )/ vc;
        }else if ((colaJug.empty()) && !(colaPc.empty())) {//cola jugador vacia
          printLog("jugador  vacia!\n");
          return (l - dist(colaJug,time,vc)) / vc;
        }else if(!(colaJug.empty()) && !(colaPc.empty())) { //ninguna cola vacia
		printLog("ninguna vacia!\n");
          return (l - (dist(colaJug,time,vc) + dist(colaPc,time,vc))) / (2*vc);
        }
};

double pesoNuevo(std::list< std::pair<double,double> > colaVenc , std::list< std::pair<double,double> > colaPerd , double time,double vc){
return colaVenc.front().first * (potencia(colaPerd,time,vc) / potencia(colaVenc,time,vc));
};

double potencia(std::list< std::pair<double,double> > cola , double time,double vc){
        return cola.front().first * dist(cola,time,vc);
};

double dist(std::list< std::pair<double,double> > cola , double time,double vc){
        return (time-cola.front().second)*vc;
};
