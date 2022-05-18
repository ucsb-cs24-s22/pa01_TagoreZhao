// Author:Tagore Zhao
#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <string>
#include "cards.h"
using namespace std; 

int CardNum (string input);
string Suit (int value);
string Num (int value);
bool StepOne(Cards& Alice, Cards& Bob);
bool StepTwo(Cards& Alice, Cards& Bob);

#endif