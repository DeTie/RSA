#include <iostream>
#include <cstring>
#pragma once
//prevent redefinition

using namespace std;

string decitoHexa(int input, int blckLength){
    //blckLength defines the length of each encryted block
    string result;
    char tail;
    int count = 0;
    do{
        switch(input % 16){
            case 0:tail = '0';break;
            case 1:tail = '1';break;
            case 2:tail = '2';break;
            case 3:tail = '3';break;
            case 4:tail = '4';break;
            case 5:tail = '5';break;
            case 6:tail = '6';break;
            case 7:tail = '7';break;
            case 8:tail = '8';break;
            case 9:tail = '9';break; 
            case 10:tail = 'A';break;
            case 11:tail = 'B';break;
            case 12:tail = 'C';break;
            case 13:tail = 'D';break;
            case 14:tail = 'E';break;
            case 15:tail = 'F';break;
            default:break;
        }
        input = input / 16;
        result = tail + result;
        count ++;
    }while(input > 0 && count <= blckLength);
    
    if(count <= blckLength){
        //add extra "0" to the head if the length is smaller than blockLength
        for(int i = 0;i < blckLength - count;i ++){
            result = "0" + result;
        }
    }
    else
    {
        //Input overflow
        cout<<"Input overflow!"<<endl;
        system("pause");
        return NULL;
    }
    return result;
}

int hexatoDeci(string input, int blckLength){
    int result = 0;
    int temp;

    if(input.length() != blckLength){
        cout<<"Input error!"<<endl;
        system("pause");
        return -1;
    }

    for(int i = 0; i < blckLength; i ++){
        switch (input[i]){
            case '0':temp = 0;break;
            case '1':temp = 1;break;
            case '2':temp = 2;break;
            case '3':temp = 3;break;
            case '4':temp = 4;break;
            case '5':temp = 5;break;
            case '6':temp = 6;break;
            case '7':temp = 7;break;
            case '8':temp = 8;break;
            case '9':temp = 9;break;
            case 'A':temp = 10;break;
            case 'B':temp = 11;break;
            case 'C':temp = 12;break;
            case 'D':temp = 13;break;
            case 'E':temp = 14;break;
            case 'F':temp = 15;break;
            default:cout<<"Input error!"<<endl;break;
        }
        result *= 16;
        result += temp;
    }
    return result;
}

int blockLength(int n){
    int i = 1;
    while(n / 16 != 0){
        i++;
        n/=16;
    }
    return i;
}

// int main(){
//     cout << hexatoDeci("001F",3)<<endl;
//     system("pause");
//     return 0;
// }