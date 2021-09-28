#include <iostream>
#include <cmath>
#include <string>
#include "radix.Translate.cpp"

using namespace std;

int intEncrypt (int input, int e, int n){
    input %= n;
    //sometimes input is too large, which lets temp*input overflows
    //so the input would be pre-mod by n
    int temp = 1;
    for(int i = 0;i < e;i ++ ){
        temp *= input;
        temp %= n;
    }
    return temp;
}



string textEncrypt (string input, int e, int n){
    string result ="";
    int bLength = blockLength(n);
    for(int i = 0;i < input.length();i ++ ){
        int charAsci = input[i]; 
        charAsci = intEncrypt(charAsci,e,n);
        result = result + decitoHexa(charAsci,bLength);
    }
    return result;
}

