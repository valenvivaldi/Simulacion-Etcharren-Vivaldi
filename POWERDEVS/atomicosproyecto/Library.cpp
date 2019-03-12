#include "Library.h"

double calculateSigma(std::list< std::pair<double,double> >colaJug  , std::list< std::pair<double,double> > colaPc , double time, double l, double vc){
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

double newWeight(std::list< std::pair<double,double> > colaVenc , std::list< std::pair<double,double> > colaPerd , double time,double vc){
    return colaVenc.front().first * (power(colaPerd,time,vc) / power(colaVenc,time,vc));
};

double power(std::list< std::pair<double,double> > cola , double time,double vc){
    return cola.front().first * dist(cola,time,vc);
};

double power(double weigth, double distance){
	return weigth*distance;
	}

double dist(std::list< std::pair<double,double> > cola , double time,double vc){
    return ((time-(cola.front().second))*vc);
};

void showQueue (std::list< std::pair<double,double> > cola){
	printLog("{");
	for (std::list<std::pair<double,double> >::iterator it=cola.begin(); it != cola.end(); ++it){
		printLog("%f,",(*it).first);
	}
	printLog("}\n");
}
