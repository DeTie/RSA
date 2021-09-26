#include <iostream>
#include <cmath>
#include "radix.Translate.cpp"
using namespace std;

int intDecrypt(int input, int d, int n){
    input %= n;
    //sometimes input is too large, which lets temp*input overflows
    //so the input would be pre-mod by n
    int temp = 1;
    for(int i = 0;i < d;i ++ ){
        temp *= input;
        temp %= n;
    }

    //sometimes this error would occur, left for debugging
    if (temp < 33 || temp > 126){
            cout << "Char translation error!"<<endl;
            system("pause");
        }
    return temp;

}

string textDecrypt (string input, int d, int n){
    string result = "";
    int bLength = blockLength(n);
    if(input.length() % bLength != 0){
        cout << "Input error!"<<endl;
        return NULL;
    }
    for(int i = 0;i < input.length();i += bLength){
        string temp = input.substr(i,bLength);
        int encryptedChar = hexatoDeci(temp,bLength);
        int  intElement = intDecrypt(encryptedChar,d,n);
        char charElement = intElement;
        result = result+charElement;
    }
    return result;
}



