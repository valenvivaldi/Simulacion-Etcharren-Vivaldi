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

