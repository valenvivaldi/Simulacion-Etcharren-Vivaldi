#include "Library.h"

double calcularsigma(std::list< std::pair<double,double> >colaJug  , std::list< std::pair<double,double> > colaPc , double time, double l, double vc){
    if(!(colaJug.empty())&& (colaPc.empty())) { //cola pc vacia
    	//printLog("pc  vacia!\n");
        return (l - dist(colaJug,time,vc) )/ vc;
    }else if ((colaJug.empty()) && !(colaPc.empty())) {//cola jugador vacia
        //printLog("jugador  vacia!\n");
        return (l - dist(colaPc,time,vc)) / vc;
    }else if(!(colaJug.empty()) && !(colaPc.empty())) { //ninguna cola vacia
		//printLog("ninguna vacia!\n");
        return (l - (dist(colaJug,time,vc) + dist(colaPc,time,vc))) / (2*vc);
    }else{
        return std::numeric_limits<double>::max();
    }
    //printLog("%lf\n", sig);
};

double pesoNuevo(std::list< std::pair<double,double> > colaVenc , std::list< std::pair<double,double> > colaPerd , double time,double vc){
    return colaVenc.front().first * (potencia(colaPerd,time,vc) / potencia(colaVenc,time,vc));
};

double potencia(std::list< std::pair<double,double> > cola , double time,double vc){
    return cola.front().first * dist(cola,time,vc);
};

double potencia(double weigth, double distance){
	return weigth*distance;
	}

double dist(std::list< std::pair<double,double> > cola , double time,double vc){
    return ((time-(cola.front().second))*vc);
};

void mostrarCola (std::list< std::pair<double,double> > cola){
	printLog("{");			
	for (std::list<std::pair<double,double> >::iterator it=cola.begin(); it != cola.end(); ++it){
		printLog("%f,",(*it).first);	
	}				
	printLog("}\n");
}
