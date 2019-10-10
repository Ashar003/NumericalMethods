#include <iostream>
#include <math.h> 
using namespace std;

long factorias ( int t){
    unsigned long factorialO = 1;
    for(int i = 1; i <=t; ++i)
    {
        factorialO *= i;
    }
    return factorialO;
}


double exp_sum(double x){
    int nMax = 30;
    double EXP = 0.0;
    for(int i= 0; i<= nMax; i++){
        if(i == 0){ EXP = EXP +1;}
        else{
        // if(i == 1){ EXP = EXP + x; break;};
        EXP = EXP + (pow(x, i) / factorias(i));
    }
    }
    return EXP;
}




int main(){

    double e = 0.2;
    double myRes= exp_sum(e);
    double result = exp(e);

    double s = abs(myRes - result);
    

    cout<<myRes<<" What I calculated\n"<<result<<" what library calculates\n "<<s<<" ABS value difference\n";
}

