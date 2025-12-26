#pragma once
#include <iostream>
#include "Node.hh"

class BST{
    std::unique_ptr<Node> root=nullptr;
    // Since users don't need to bother with pointers;
    void addHelper(int, std::unique_ptr<Node>&);
    void delHelper(int, std::unique_ptr<Node>&);
    void travHelper(std::unique_ptr<Node>& r);
    
    public:
    BST();
    BST(int);

    void add(int);
    void remove(int);
    void traverse();
};