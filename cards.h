// root.h
// Author: Tagore Zhao
// All class declarations go here

#ifndef CARDS_H
#define CARDS_H
#include <iostream>
#include <string>
using namespace std;

class Cards {
    public:
    // ctor, dtor, insert and one print method already done in intbst.cpp:
    Cards();                   // constructor
    ~Cards();                  // destructor
    bool insert(int v);     // insert value; return false if duplicate
    void printPreOrder() const; // prints tree data pre-order to cout

    // 8 METHODS YOU MUST IMPLEMENT in intbst.cpp:
    void printInOrder() const;       // print tree data in-order to cout
    void printPostOrder() const;     // print tree data post-order to cout
    int count() const;               // count of values
    bool contains(int value) const;  // true if value is in tree
    int Min() const;
    int Max() const;
    

    // THESE ARE HARDER! DO THESE LAST
    int getPredecessor(int value) const;       // returns the predecessor value of the given value or 0 if there is none
    int getSuccessor(int value) const;         // returns the successor value of the given value or 0 if there is none
    bool remove(int value);                    // deletes the Node containing the given value from the tree

 private:

    struct Node {
	int info;
	Node *left, *right, * parent;
	// useful constructor:
    Node(int v=0) : info(v), left(0), right(0), parent(0) { }
    };

    // just one instance variable (pointer to root node):
    Node *root;

    // recursive utility functions for use by public methods above
    Node* getNodeFor(int value, Node* n) const; // IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
    void clear(Node *n); // for destructor
    bool insert(int value, Node *n); // note overloading names for simplicity
    void printPreOrder(Node *n) const;
    void printInOrder(Node *n) const;
    void printPostOrder(Node *n) const;
    int count(Node *n) const;
    Node* Min(Node* &n)const;
    Node* Max(Node* &n)const;

    // these should be used by getPredecessor and getSuccessor, and ONE of them should be used by remove
    Node* getSuccessorNode(int value) const;   // returns the Node containing the successor of the given value
    Node* getPredecessorNode(int value) const; // returns the Node containing the predecessor of the given value 
};


#endif
