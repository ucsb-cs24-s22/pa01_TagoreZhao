// Author:Tagore Zhao
#include <iostream>
#include <fstream>
#include <string>
#include "utility.h"
#include "cards.h"
#include "utility.cpp"
#include "cards.cpp"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }

  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }
/*
Cards* A = new Cards;
Cards* B = new Cards;
*/

Cards A,B;

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    int n = CardNum(line);
    A.insert(n);
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    int m = CardNum(line);
    B.insert(m);
  }
  cardFile2.close();
/*
cout << endl << "Alice's cards:" << endl;
  A.printInOrder();
  cout << endl << "Bob's cards:" << endl;
  B.printInOrder();
*/
  while(true){
    bool l = StepOne(A, B);
    if(l == true){
      break;
    }
    bool f = StepTwo(A, B);
    if(f == true){
      break;
    }
  }

  cout << endl << "Alice's cards:" << endl;
  A.printInOrder();
  cout << endl << "Bob's cards:" << endl;
  B.printInOrder();
  return 0;
}

