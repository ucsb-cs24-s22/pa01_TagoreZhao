#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"
#include "cards.cpp"

#include "utility.h"
#include "utility.cpp"
using namespace std;

int main(){
  /*  cout << "hello world!"<< endl;
    cout << CardNum("s j") << endl;
    cout << CardNum("s 10") << endl;
    cout << CardNum("d 9") << endl;
    cout << CardNum("c k") << endl;
    cout << CardNum("h 1") << endl;
    cout << CardNum("d 6") << endl;
    cout << CardNum("s 5") << endl;
    */
    Cards A,B;
    A.insert(CardNum("s j"));
    A.insert(CardNum("s 10"));
    A.insert(CardNum("d 9"));
    A.insert(CardNum("c k"));
    A.insert(CardNum("h 1"));
    A.insert(CardNum("d 6"));
    A.insert(CardNum("s 5"));


    A.printInOrder();
    A.printPreOrder();
    cout <<endl;
    cout << "predecessor of s j: "<<A.getPredecessor(CardNum("s j"));
    cout <<endl;
    cout << "successor of s j: "<<A.getSuccessor(CardNum("s j"));
    cout <<endl;
    cout << "Max: "<<A.Max()<<endl;
    cout << "Min: "<<A.Min()<<endl;
}

