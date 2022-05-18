// Author:Tagore Zhao
#include <iostream>
#include <string>
#include "cards.h"
#include "utility.h"
using namespace std; 

int CardNum (string input){
    int cSuit;
    int Val;
    string Suit = input.substr(0,1);
    if(Suit == "c"){cSuit = 100;}
    else if(Suit == "d"){cSuit = 200;}
    else if(Suit == "s"){cSuit = 300;}
    else if(Suit == "h"){cSuit = 400;}

    string Value = input.substr(2);
    if(Value == "a"){Val = 1;}
    else if(Value == "j"){Val = 11;}
    else if(Value == "q"){Val = 12;}
    else if(Value == "k"){Val = 13;}
    else{
        Val = stoi(Value);
    }
    int sum  = cSuit + Val;
    return sum;           
}

string Suit (int value){
    string suit;
    suit = to_string(value).substr(0,1);
    if(suit == "1"){suit = "c";}
    else if(suit == "2"){suit = "d";}
    else if(suit == "3"){suit = "s";}
    else if(suit == "4"){suit = "h";}
    return suit;
}
string Num (int value){
    string v;
    v = to_string(value).substr(1);
    if(v.substr(0,1) == "0"){
        if(v == "01"){v = "a";}
        else{v = v.substr(1);}
    }
    else{
        if(v == "11"){v = "j";}
        else if(v == "12"){v = "q";}
        else if(v == "13"){v = "k";}
    }
    return v;
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
                cout << "Alice picked matching card " << Suit(a) <<" "<< Num(a)<<endl;
                return false;
            }    
        }
    return true;
    }
}
bool StepTwo(Cards& Alice, Cards& Bob){
    int min = Bob.Min();
    int max = Bob.Max();
    int b = max;
    if (max == 0 || min == 0){
        return true;
    }
    if(Alice.contains(max)){
        Bob.remove(max);
        Alice.remove(max);
        cout << "Bob picked matching card " << Suit(max) <<" "<< Num(max)<<endl;
        return false;
    }
    else{
        while (b != min){
            b = Bob.getPredecessor(b);
            if (Alice.contains(b)){
                Bob.remove(b);
                Alice.remove(b);
                cout << "Bob picked matching card " << Suit(b) <<" "<< Num(b)<<endl;
                return false;
            }
        }
    return true;
    }
}

