// root.cpp
// Author:Tagore Zhao
// Implementation of the classes defined in root.h
#include "cards.h"
#include "utility.h"
#include <string>
#include <iostream>
using std::cout;


Cards::Cards(){
    root = nullptr;
}  // constructor
Cards::~Cards(){
    clear(root);
}   // destructor
int Cards::Min() const{
    Node* n = root;
    if (n == nullptr){
        return 0;
    }
    return Min(n)->info;
}
int Cards::Max() const{
    Node* n = root;
    if (n == nullptr){
        return 0;
    }
    return Max(n)->info;
}
Cards::Node* Cards::Min(Node* &n)const{
    if(n->left == nullptr){
        return n;
    }
    else{
        return Min(n->left);
    }
}
Cards::Node* Cards::Max(Node* &n)const{
    if(n->right == nullptr){
        return n;
    }
    else{
        return Max(n->right);
    }
} 
void Cards::clear(Node *n){
    if (n == nullptr){
        return;
    }
    if (n->left) {
        clear(n->left);
    }
    if (n->right) {
        clear(n->right);
    }
    delete n;
}
bool Cards::insert(int v){
    //Change insert helper into putting int value, reduce redundency.
    if (root == nullptr){
        root =  new Node;
        root->info = v;
        return true;
    }
    return insert(v,root);
}

bool Cards::insert(int value, Node *n) { 
    if (value == n->info)
        return false;
    if (value < n->info) {
        if (n->left){
            return insert(value, n->left);}
        else {
            n->left = new Node(value);
            n->left->parent = n;
            return true;
        }
    }
    else {
        if (n->right){
            return insert(value, n->right);}
        else {
            n->right = new Node(value);
            n->right->parent = n;
            return true;
        }
    }
}
void Cards::printPreOrder() const{
    printPreOrder(root);
}
void Cards::printPreOrder(Node *n) const{
    if (n == nullptr){
        return;
    }
    cout << Suit(n->info) <<" "<< Num(n->info) <<endl; // IMPLEMENT HERE
    if (n->left&&n->right){
        printPreOrder(n->left);
        printPreOrder(n->right);
    }else if (n->left&&(n->right==nullptr)){
        printPreOrder(n->left);
    }else if (n->right&&(n->left==nullptr)){
        printPreOrder(n->right);
    }
    else {
        return;
    }
}
void Cards::printInOrder() const{
    printInOrder(root);
    cout << endl;
}
void Cards::printInOrder(Node *n) const{
    if (n == nullptr){
        return;
    }
    if (n->left){
        printInOrder(n->left);
    }

    cout << Suit(n->info) <<" "<< Num(n->info) <<endl; // IMPLEMENT HERE

    if (n->right){
        printInOrder(n->right);
    }
}
void Cards::printPostOrder() const{
    printPostOrder(root);
    cout << endl;
}
void Cards::printPostOrder(Node *n) const{
    if (n == nullptr){
        return;
    }
    if (n->left){
        printPostOrder(n->left);
    }
    if (n->right){
        printPostOrder(n->right);
    }
    cout << Suit(n->info) <<" "<< Num(n->info) <<endl;
}
int Cards::count() const{
    return count(root);
}
int Cards::count(Node *n) const{
    if (n == nullptr){
        return 0;
    }
    int m = 1;
    if (n->left){
        m += count(n->left);
    }
    if (n->right){
        m += count(n->right);
    } 
    return m;
}
        

bool Cards::contains(int value) const{
    Node *n = root;
    if (n == nullptr){
        return false;
    }
    n = getNodeFor(value,n);
    if (n->info == value) {
        return true;
    }
    return false;
}

Cards::Node* Cards::getNodeFor(int value, Node* n) const{
    if (n == nullptr){
        return NULL;
    }
    if (n->info < value && n->right){
        n = getNodeFor(value,n->right);
    }
    if (n->info > value && n->left){
        n = getNodeFor(value,n->left);
    }
    if (n->info == value) {
        return n;
    }
    return n;
}

int Cards::getSuccessor(int value) const{
    Node *n =getSuccessorNode(value);
    if (n == nullptr){
        return 0;
    }
    return n->info;
}         // returns the successor value of the given value or 0 if there is none
Cards::Node* Cards::getSuccessorNode(int value) const{
    Node* r = root;
    Node* n = getNodeFor(value,r);
    if (r == nullptr){
        return n;
    }
    if(!contains(value)){
        return nullptr;
    }
    if(n->right){
        n = n->right;
            while (n->left){
                n = n->left;
            }
            return n;
    }else{
        Node* suc = nullptr;
        Node* a = root;
        while(a != n){
            if(n->info < a->info){
                suc = a;
                a = a->left;
            }else{
                a = a->right;
            }
        }
        return suc;
    }
}
   // returns the Node containing the successor of the given value
int Cards::getPredecessor(int value) const{
    Node *n =getPredecessorNode(value);
    if (!n){
        return 0;
    }
    return n->info;
}       // returns the predecessor value of the given value or 0 if there is none
Cards::Node* Cards::getPredecessorNode(int value) const{
    Node* r = root;
    Node* n = getNodeFor(value,r);
    if (r == nullptr){
        return n;
    }
    if(!contains(value)){
        return nullptr;
    }
    if (n->left){
        n = n->left;
        while (n->right){
            n = n->right;
        }
            return n;
    }else{
        Node* suc = nullptr;
        Node* a = root;
        while(a != n){
            if(n->info > a->info){
                suc = a;
                a = a->right;
            }else{
                a = a->left;
            }
        }
        return suc;
    }
} // returns the Node containing the predecessor of the given value 
bool Cards::remove(int value){
    if(!contains(value)){
        return false;}

    Node *n = getNodeFor(value, root);
    if(n && n->left == nullptr && n->right == nullptr) {
        if(n->parent == nullptr){            
            delete n;
            root = nullptr;}
        else{
            if(n == n->parent->left){
                n->parent->left = nullptr;
                delete n;
                return true;
            }
            else{
                n->parent->right = nullptr;
                delete n;
                return true;
            }
        }      
    }
    else if((n->left && n->right == nullptr)||( n->right && n->left == nullptr)){
        if(!n->left){
            if(!n->parent){
                root = n->right;
                delete n;
                root->parent = nullptr;
                return true;
            }
            else{
                if(n == n->parent->left){ 
                    n->parent->left = n->right;
                    n->right->parent = n->parent;
                }
                else{ 
                    n->parent->right = n->right;
                    n->right->parent = n->parent;
                }
                delete n;
                return true;}
        }
        if(!n->right){
            if(!n->parent){
                root = n->left;
                delete n;
                root->parent = nullptr;
                return true;
            }
            else{
                if(n == n->parent->left){
                    n->parent->left = n->left;
                    n->left->parent = n->parent;
                }
                else{ 
                    n->parent->right = n->left;
                    n->left->parent = n->parent;
                }
                delete n;
                return true;}
        }
    }
    else{
        int suc_val = getSuccessor(value); 
        remove(suc_val);
        n->info = suc_val;
        return true; 
    }
    return false;
}