#include <NumberGenLibrary.h>

std::vector<double> genExponentialDistribution(double mean, int qty){
    std::vector<double> arrExp;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::exponential_distribution<double> distExp(1.0/mean);
    for (int i=0; i<qty; i++){
        arrExp.push_back(distExp(generator));
    }
    return arrExp;
};

std::vector<double> genUniformDistribution(double min, double max, int qty){
    std::vector<double> arrUn;
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
    std::vector <double> myvector =  genUniformDistribution(6,90,30);
    //std::list<double>::iterator it = mylist.begin();
    double n=0;

    std::cout << "media" << n/myvector.size() << std::endl;
    std::sort (myvector.begin(),myvector.end());
    for (std::vector <double>::iterator it=myvector.begin(); it != myvector.end(); ++it){
        std::cout << *it << std::endl;
        n += *it;
        if (*it<6 || *it>9){
            std::cout << "maall" << std::endl;

        }  
    }
    std::cout << "media" << n/myvector.size() << std::endl;

    return 0;
};*/

