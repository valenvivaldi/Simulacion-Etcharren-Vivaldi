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
    printLog("lista:{");
    for(it = a.begin(); it != a.end(); ++it){
        printLog("%g,",*it);
    }
    printLog("}\n");
}

void interleaved(std::list<double> *a){
    std::list<double> res;
    bool i=0;
    while(!(*a).empty()){
        if(i){
                res.push_back((*a).front());
                (*a).pop_front();
                i=!i;
        }else{
                res.push_back((*a).back());
                (*a).pop_back();
                i=!i;
        }
    }
    *a = res;
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

double popWeightMayorPcElem(std::list<double>* weights,double enemyWeight){
    if((*weights).size()<=0){
        return -1;
    } 
    std::list<double>::iterator it = (*weights).begin();
    while(it!=(*weights).end()){
        //printLog("%g lo supera? ",*it);
        if(*it>enemyWeight){
            break;
        }else{
            it++;
        }
    }
    double res;
    if(it == (*weights).end()){ // no se encontro un elemento que le gane, se envia un elento random
        res = popRandomElement(weights);
    }else{
        res = *it;
        (*weights).erase(it);
    }
    (*weights).erase(it);
    //printLogList(*weights);
    //printLog("TERMINO SELECCION DE POSIBLE GANADOR: %g\n",res);
    return res;
}


double pickPossibleWinner(std::list<double> *weights, double enemyWeight, double enemyDistance, double length ){
    if((*weights).size()<=0){
        return -1;
    } 
    std::list<double>::iterator it = (*weights).begin();
    double collitionPlace = (length - enemyDistance)/2 ;  //distancia donde ocurriria la colision
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
    double res;
    if(it == (*weights).end()){ // no se encontro un elemento que le gane, se envia un elento random
        res = popRandomElement(weights);
    }else{
        res = *it;
        (*weights).erase(it);
    }
    return res;
    //printLogList(*weights);
    //printLog("TERMINO SELECCION DE POSIBLE GANADOR: %g\n",res);
}

bool checkPossibleWinner(std::list<double> weights, double enemyWeight, double enemyDistance, double length){
    if((weights).size()<=0){
        return 0;
    }
    double collitionPlace = (length - enemyDistance)/2 ;
    double powerEnemy = power(enemyWeight,enemyDistance+collitionPlace);
        //printLog("Vamos a checkear si el peso mas grande  de los que quedan, le gana al elemento ganador\n");
    if(power((weights).back(),collitionPlace)>powerEnemy){
        //printLog("Le gana! mandamos el mas chico posible\n");
        return 1;
    }else{
        //printLog("El mas grande no le gana, entonces no mandamos nada!\n");
        return 0;
    }
}
