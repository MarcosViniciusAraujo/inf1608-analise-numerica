#include "taylor.h"

double tan1(double x){
    return x + (x*x*x)/3.0 + 2.0*(x*x*x*x*x)/15.0;
}

double tan2(double x){
    return (x - (x*x*x)/6.0)/(1.0 - (x*x)/2.0);
}