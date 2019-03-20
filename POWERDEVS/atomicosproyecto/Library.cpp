#include "Library.h"

double calculateSigma(std::list< std::pair<double,double> >playerQueue  , std::list< std::pair<double,double> > pcQueue , double time, double l, double vc){
    if(!(playerQueue.empty())&& (pcQueue.empty())) { //queue pc vacia
    	//printLog("pc  vacia!\n");
        return (l - dist(playerQueue,time,vc) )/ vc;
    }else if ((playerQueue.empty()) && !(pcQueue.empty())) {//queue jugador vacia
        //printLog("jugador  vacia!\n");
        return (l - dist(pcQueue,time,vc)) / vc;
    }else if(!(playerQueue.empty()) && !(pcQueue.empty())) { //ninguna queue vacia
		//printLog("ninguna vacia!\n");
        return (l - (dist(playerQueue,time,vc) + dist(pcQueue,time,vc))) / (2*vc);
    }else{
        return std::numeric_limits<double>::max();
    }
    //printLog("%lf\n", sig);
}

double newWeight(std::list< std::pair<double,double> > winnerQueue , std::list< std::pair<double,double> > loserQueue , double time,double vc){
    return winnerQueue.front().first * (power(loserQueue,time,vc) / power(winnerQueue,time,vc));
}

double weightSecondElement(std::list< std::pair<double,double> > queue){
    if(queue.size()<2){return 0;}
    std::list< std::pair<double,double> >::iterator it = queue.begin();
    it++;
    return it->first ;

}
double power(std::list< std::pair<double,double> > queue , double time,double vc){
    return queue.front().first * dist(queue,time,vc);
}

double power(double weigth, double distance){
	return weigth*distance;
}

double dist(std::list< std::pair<double,double> > queue , double time,double vc){
    return ((time-(queue.front().second))*vc);
}

double distSecond(std::list< std::pair<double,double> > queue , double time,double vc){
    if(queue.size()<2){return 0;}
    std::list< std::pair<double,double> >::iterator it = queue.begin();
    it++;
    return ((time-(it->second))*vc);
}

void showQueue (std::list< std::pair<double,double> > queue){
	//printLog("{");
	for (std::list<std::pair<double,double> >::iterator it=queue.begin(); it != queue.end(); ++it){
		//printLog("%f,",(*it).first);
	}
	//printLog("}\n");
}
