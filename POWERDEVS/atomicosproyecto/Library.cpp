#include "Library.h"

double calculateSigma(std::list< std::pair<double,double> >playerQueue  , std::list< std::pair<double,double> > pcQueue , double time, double l, double vc){
    if(!(playerQueue.empty())&& (pcQueue.empty())) { //cola pc vacia
    	//printLog("pc  vacia!\n");
        return (l - dist(playerQueue,time,vc) )/ vc;
    }else if ((playerQueue.empty()) && !(pcQueue.empty())) {//cola jugador vacia
        //printLog("jugador  vacia!\n");
        return (l - dist(pcQueue,time,vc)) / vc;
    }else if(!(playerQueue.empty()) && !(pcQueue.empty())) { //ninguna cola vacia
		//printLog("ninguna vacia!\n");
        return (l - (dist(playerQueue,time,vc) + dist(pcQueue,time,vc))) / (2*vc);
    }else{
        return std::numeric_limits<double>::max();
    }
    //printLog("%lf\n", sig);
};

double newWeight(std::list< std::pair<double,double> > winnerQueue , std::list< std::pair<double,double> > loserQueue , double time,double vc){
    return winnerQueue.front().first * (power(loserQueue,time,vc) / power(winnerQueue,time,vc));
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
	//printLog("{");
	for (std::list<std::pair<double,double> >::iterator it=cola.begin(); it != cola.end(); ++it){
		//printLog("%f,",(*it).first);
	}
	//printLog("}\n");
}
