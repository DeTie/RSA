#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include "key.Generator.cpp"
#include "text.Decrypt.cpp"
#include "text.Encrypt.cpp"

using namespace std;

int main(){
    string raw_String;
    srand((unsigned)time(NULL));
    
    //Set global seed

    int * key = keyGen();
    cout << "Key sets:" <<endl;
    cout <<"n:"<<key[0]<<" e:"<<key[1]<<" n:"<<key[2]<<" d:"<<key[3]<<endl;
    cout << "Input text:" <<endl;
    cin >> raw_String;
    //recently can only input string without spaces
    
    cout <<"Encrypted text:"<<endl;
    
    string encryptedText = textEncrypt(raw_String,key[1],key[0]);
    cout <<encryptedText<<endl;
    cout <<"Decrypted text:"<<endl;
    cout <<textDecrypt(encryptedText,key[3],key[2])<<endl;
    system("pause");
    return 0;
}
