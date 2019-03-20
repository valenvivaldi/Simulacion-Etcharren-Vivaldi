#include "NumberGenLibrary.h"

std::list<double> genExponentialDistribution(double mean, int qty,unsigned int seed){
    std::list<double> arrExp;

    std::mt19937 generator;
    if(seed == 0){
		std::random_device rd;
		generator.seed(rd());
	}else{
	generator.seed(seed);

	}
    double num;
    double total=0;
    int entero1 =0;
    int entero2=0;
    int entero3 =0;
    std::exponential_distribution<double> distExp(1.0/mean);
    for (int i=0; i<qty; i++){
        num = distExp(generator);
        total+= num;
        arrExp.push_back(num);
        if(num<5){entero1++;
        }else if(num>10){
          entero2++;
        }else{entero3++;}
    }
    printLog ("media  %g\n", total / qty);
    printLog("menores que 5 %d \n",entero1);
    printLog("normales  %d \n",entero3);
    printLog("mayores que 10 %d \n",entero2);
    return arrExp;
};

std::list<double> genUniformDistribution(double min, double max, int qty,unsigned int seed){
    std::list<double> arrUn;
    std::mt19937 generator;
    if(seed == 0){
		std::random_device rd;
		generator.seed(rd());
	}else{
	generator.seed(seed);
	}
    std::uniform_real_distribution<double> distUn(min, max);
    for (int i=0; i<qty; i++){
        arrUn.push_back(distUn(generator));
    }
    return arrUn;
};

void printLogList(std::list<double> a){
	std::list<double>::iterator it;
	//printLog("lista:{");
	for(it = a.begin(); it != a.end(); ++it){
		//printLog("%g,",*it);
	}
	//printLog("}\n");
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

//precondicion: a.size()>0

double popRandomElement(std::list<double>* a){
    //printLog("Necesitamos un aleatorio de esta lista \n");
    //printLogList(*a);
	int num=rand()%(*a).size();
	std::list<double>::iterator it = (*a).begin();
	advance(it,num);
	double res = *it;
	(*a).erase(it);
	//printLogList(*a);
    //printLog("enviamos a %g \n",res);
	return res;
}

//precondicion: a.size()>0
double pickPossibleWinner(std::list<double>* weights, double enemyWeight, double enemyDistance, double length ){
  std::list<double>::iterator it = (*weights).begin();
	double collitionPlace = (length - enemyDistance)/2 ;  //distancia que tendria el peso al momento de colisionar con el peso a vencer
	double powerEnemy = power(enemyWeight,enemyDistance+ collitionPlace);

	//printLog("comienza la busqueda de un posible ganador\n");
	//printLog("necesitamos a alguien que supere una potencia de %g, a la distanicia de %g \n",powerEnemy,collitionPlace);
	//printLogList(*weights);
	while(it!=(*weights).end()){

		//printLog("%g lo supera? ",*it);
		if(power(*it,collitionPlace)>powerEnemy){

			break;
		}else{
			it++;

		}
	}
	if(it == (*weights).end()){
		it = (*weights).begin();
	}
	double res = *it;
	(*weights).erase(it);
	//printLogList(*weights);
	//printLog("TERMINO SELECCION DE POSIBLE GANADOR: %g\n",res);

	return res;

}

bool checkPossibleWinner(std::list<double>* weights, double enemyWeight, double enemyDistance, double length){
  if((*weights).size()<=0){
    return 0;
  }
	double collitionPlace = (length - enemyDistance)/2 ;
	double powerEnemy = power(enemyWeight,enemyDistance+collitionPlace);
		//printLog("Vamos a checkear si el peso mas grande  de los que quedan, le gana al elemento ganador\n");
		if(power((*weights).back(),collitionPlace)>powerEnemy){
			//printLog("Le gana! mandamos el mas chico posible\n");
			return 1;
		}else{
			//printLog("El mas grande no le gana, entonces no mandamos nada!\n");
			return 0;
		}



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
