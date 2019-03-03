#include "NumberGenLibrary.h"

std::list<double> genExponentialDistribution(double mean, int qty){
    std::list<double> arrExp;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::exponential_distribution<double> distExp(1.0/mean);
    for (int i=0; i<qty; i++){
        arrExp.push_back(distExp(generator));
    }
    return arrExp;
};

std::list<double> genUniformDistribution(double min, double max, int qty){
    std::list<double> arrUn;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<double> distUn(min, max);
    for (int i=0; i<qty; i++){
        arrUn.push_back(distUn(generator));
    }
    return arrUn;
};

void printLogList(std::list<double> a){
	std::list<double>::iterator it;
	printLog("lista:{");
	for(it = a.begin(); it != a.end(); ++it){
		printLog("%g,",*it);
	}
	printLog("}\n");
}

std::list<double> interleaved(std::list<double> a){
    std::list<double> res;
    bool i=0;
    while(!a.empty()){
		if(i){
				res.push_back(a.front());
				a.pop_front();
				i=!i;
		}else{
				res.push_back(a.back());
				a.pop_back();
				i=!i;
		}
	}
    return res;
};

double popRandomElement(std::list<double>* a){
	if((*a).size()==0){return 999999999;}
	printLogList(*a);
	int num=rand()%(*a).size();
	std::list<double>::iterator it = (*a).begin();
	
	advance(it,num);
	int res = *it;
	
	(*a).erase(it);
	printLogList(*a);
	
	return res;
}

double pickPossibleWinner(std::list<double>* weights, double enemyWeight, double enemyDistance, double length ){
	std::list<double>::iterator it = (*weights).begin();
	double powerEnemy = potencia(enemyWeight,enemyDistance);
	double distanciaEncuentro = (length - enemyDistance)/2;
	double pesoSiguiente;
	printLog("comienza la busqueda de un posible ganador\n");
	printLog("necesitamos a alguien que supere una potencia de %g, a la distanicia de %g \n",powerEnemy,distanciaEncuentro);
	printLogList(*weights);
	while(it!=(*weights).end()){
		pesoSiguiente=*(next(it));
		printLog("%g lo supera? ",pesoSiguiente);
		if(potencia(pesoSiguiente,distanciaEncuentro)>powerEnemy){
			printLog("si, a ver el siguiente\n");
			it++;
		}else{
			printLog("no, entonces mando el anterior que es %g\n",*it);
			break;
		}
	
	}
	int res = *it;
	(*weights).erase(it);
	printLogList(*weights);
	printLog("TERMINO SELECCION DE POSIBLE GANADOR\n");
	
	return res;
	
}
	
	




/*
int main(void){
    std::list <double> mylist =  genUniformDistribution(6,90,30);
    //std::list<double>::iterator it = mylist.begin();
    double n=0;

    std::cout << "media" << n/mylist.size() << std::endl;
    std::sort (mylist.begin(),mylist.end());
    for (std::list <double>::iterator it=mylist.begin(); it != mylist.end(); ++it){
        std::cout << *it << std::endl;
        n += *it;
        if (*it<6 || *it>9){
            std::cout << "maall" << std::endl;

        }  
    }
    std::cout << "media" << n/mylist.size() << std::endl;

    return 0;
};*/

