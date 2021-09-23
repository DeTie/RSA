#include <iostream>
#include <cmath>
#include <string>
#include "radix.Translate.cpp"

using namespace std;

int intEncrypt (int input, int e, int n){
    int temp = input;
    for(int i = 0;i < e-1;i ++ ){
        //start with 0 end with e-1
        temp %= n;
        //sometimes temp is too large, which lets temp*input overflows
        //when d&n is real big it still overflows, needed to be sovled
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


// int main(){
//     //int i = intEncrypt(33,33,45);
//     string aslu = "My dei dezcd";
//     //cin >> temp;
//     cout << intEncrypt(108,193,1025);
//     system("pause");
//     return 0;
// }