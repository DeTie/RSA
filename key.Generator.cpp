#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <ctime>
using namespace std;

struct AlgPara{
    int x;
    int y;
    AlgPara(){}
    AlgPara(int x, int y):x(x),y(y){}
};

AlgPara extEuAlgm (int a, int b, AlgPara algPara){
    //Extended Euclidean algorithm
    //an solution of a*x+b*y=1，while in this case, a & B are relatively primes
    //a&b are relatively primes, so they would never be mutual mutliplies
    if(a <= b){
        cout<< "a should be larger than b!"<< endl;
        AlgPara temp;
        return temp;
    }
    if(b == 0){
        algPara.x = 1;
        algPara.y = 0;
        return algPara;
    }
    algPara = extEuAlgm(b, a%b, algPara);
    //Newton's method
    int temp = algPara.x;
    algPara.x = algPara.y;
    algPara.y = temp - (a / b) * algPara.y;
    return algPara;
}

int primeGenerator(int bottom, int top){
    //Generate a random prime ranges [bottom,top]
    if(bottom >= top){
        cout << "Border Overflow!" << endl;
        return 0;
    }
    int i = 0;
    bool flag;
    do {
        i = rand() % (top - bottom + 1) + bottom;
        flag = false;
        for(int j = 2; j < (int)sqrt(i); j++){
            if(i % j == 0){
                flag = true;
                break;
            }
        }
    }while(flag);
    return i;
}

int* keyGen(){
    AlgPara algpara;
    int a = 0,b = 0;
    //Ensure A is not larger than B, or the primeGenerator won't be called 
    while(a <= b){
        a = primeGenerator(10,100);
        b = primeGenerator(10,100);
    }
    int n = a * b;
    int phi_N = (a - 1) * (b - 1);
    int e = primeGenerator(1,phi_N);
    //e should be smaller than phi_N
    algpara = extEuAlgm(phi_N,e,algpara);

    int d = algpara.y < 0 ? phi_N+algpara.y : algpara.y;
    //!!If d<0， then d = d + phi_N, why? Somebody tells me pls!!
    int check = e * d % phi_N;
    //The y of the result responds to the number whose parameter values e
    static int * key = new int[4];
    key[0]=n;
    key[1]=e;
    key[2]=n;
    key[3]=d;
    return key;
}
