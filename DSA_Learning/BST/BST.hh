#pragma once
#include <iostream>
#include "Node.hh"

class BST{
    Node *root=nullptr;
    // Since users don't need to bother with pointers;
    void addHelper(int, Node*&);
    void delHelper(int, Node*&);
    void travHelper(Node*&);
    
    public:
    BST();
    BST(int);
    ~BST();

    void add(int);
    void remove(int);
    void traverse();
};