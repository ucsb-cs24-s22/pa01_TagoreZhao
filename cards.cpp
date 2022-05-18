// root.cpp
// Author: Your name
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
   if (value == n->info){
            return false;
        }
        if (value > n->info && n->right != nullptr){
            insert(value, n->right);
        }
        else if (value> n->info && n->right == nullptr){
            Node* c = new Node;
            c->info = value;
            n->right = c;
            c->parent = n;
            c->left = nullptr;
            c->right = nullptr;
            return true;
        }
        else if(value < n->info && n->left != nullptr){
            insert(value, n->left);
        }
        else if (value < n->info && n->left == nullptr){
            Node* c = new Node;
            c -> info = value;
            n->left = c;
            c->parent = n;
            c->left = nullptr;
            c->right = nullptr;
            return true;
        }
    return true;
}
void Cards::printPreOrder() const{
    printPreOrder(root);
    cout << endl;
}
void Cards::printPreOrder(Node *n) const{
    if (n == nullptr){
        return;
    }
    cout << Suit(n->info) << Num(n->info) <<" "; // IMPLEMENT HERE
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

    cout << Suit(n->info) << Num(n->info) <<" "; // IMPLEMENT HERE

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
    cout << Suit(n->info) << Num(n->info) <<" ";
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
    Node* r = root;
    
    if (r == nullptr){
        return false;
    }
    if (!contains(value)){
        return false;
    }
    Node* cur = getNodeFor(value,r);
    Node* par = cur->parent;
    if ((cur->left == nullptr)&&(cur->right == nullptr)){
        if(par == nullptr){
            delete cur;
            r = nullptr;
            root = nullptr;
        }
        else if (par->left == cur){
            delete cur;
            par->left = nullptr;
        }else{
            delete cur;
            par->right = nullptr;
        }
        return true;
    }else if (cur->right == nullptr){
        if(par == nullptr){
            root = cur->left;
            root->parent = nullptr;
            delete cur;
        }
        else if(par->left == cur){
            par->left = cur->left;
            cur->left->parent = par;
            delete cur;

        }else{
            par->right = cur->left;
            cur->right->parent = par;
            delete cur;
        }
        return true;
    }else if(cur->left == nullptr){
        if (par == nullptr){
            root = cur->right;
            root->parent = nullptr;
            delete cur;
        }
        else if (par->left==cur){
            par->left = cur->right;
            cur->right->parent = par;
            delete cur;
        }
        else{
            par->right = cur->right;
            cur->right->parent = par;
            delete cur;
        }
        return true;
    }else{
        Node* suc = getSuccessorNode(value);
        int a;
        a = suc->info;
        remove(a);
        cur->info = a;
        return true;
    }
    return false; 
}
