#include <iostream>
#include <string>
#include "cards.h"
#include "utility.h"
using namespace std; 

int CardNum (string input){

    int suit;
    int number;
    int Num;
    string info =input.substr(0,1);
    if (info == "c"){
        suit = 100;
    }
    else if (info == "d"){
        suit = 200;
    }
    else if (info == "s"){
        suit = 300;
    }
    else if (info == "h"){
        suit = 400;
    }
    info = input.substr(2);
    if (info == "1"){
            number = 1;
        }
        else if(info == "2"){
            number = 2;
        }
        else if(info == "3"){
            number = 3;
        }
        else if(info == "4"){
            number = 4;
        }
        else if(info == "5"){
            number = 5;
        }
        else if(info == "6"){
            number = 6;
        }
        else if(info == "7"){
            number = 7;
        }
        else if(info == "8"){
            number = 8;
        }
        else if(info == "9"){
            number = 9;
        }
        else if(info == "10"){
            number = 10;
        }
        else if(info == "j"){
            number = 11;
        }
        else if(info == "q"){
            number = 12;
        }
        else if(info == "k"){
            number = 13;
        }
    Num = number +suit;
    return Num;           
}

string Suit (int value){
    int suit = value / 100;
    if (suit == 1){
        return "c";
    }
    else if (suit == 2){
        return "d";
    }
    else if (suit == 3){
        return "s";
    }
    else{
        return "h";
    }
}
string Num (int value){
    int num = value % 100;
    if (num == 1){
        return "1";
    }
    else if (num == 2){
        return "2";
    }
    else if (num == 3){
        return "3";
    }
    else if (num == 4){
        return "4";
    }
    else if (num == 5){
        return "5";
    }
    else if (num == 6){
        return "6";
    }
    else if (num == 7){
        return "7";
    }
    else if (num == 8){
        return "8";
    }
    else if (num == 9){
        return "9";
    }
    else if (num == 10){
        return "10";
    }
    else if (num == 11){
        return "j";
    }
    else if (num == 12){
        return "q";
    }
    else{
        return "k";
    }
}
bool StepOne(Cards& Alice, Cards& Bob){
    int min = Alice.Min();
    int max = Alice.Max();
    int a = min;
    if (max == 0 || min == 0){
        return true;
    }
    if(Bob.contains(min)){
        Bob.remove(min);
        Alice.remove(min);
        cout << "Alice picked matching card " << Suit(min) <<" "<< Num(min)<<endl;
        return false;
    }
    else{
        while (a != max){
            a = Alice.getSuccessor(a);
            if (Bob.contains(a)){
                Bob.remove(a);
                Alice.remove(a);
                cout << "Alice picked matching card " << Suit(min) <<" "<< Num(min)<<endl;
                return false;
            }
        }
    return true;
    }
}
bool StepTwo(Cards& Alice, Cards& Bob){
    int min = Bob.Min();
    int max = Bob.Max();
    int a = min;
    if (max == 0 || min == 0){
        return true;
    }
    if(Alice.contains(max)){
        Bob.remove(max);
        Alice.remove(max);
        cout << "Bob picked matching card " << Suit(min) <<" "<< Num(min)<<endl;
        return false;
    }
    else{
        while (a != max){
            a = Alice.getPredecessor(a);
            if (Bob.contains(a)){
                Bob.remove(a);
                Alice.remove(a);
                cout << "Bob picked matching card " << Suit(min) <<" "<< Num(min)<<endl;
                return false;
            }
        }
    return true;
    }
}

