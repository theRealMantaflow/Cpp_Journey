#pragma once
#include "Node.hh"
#include <iostream>

class AVL {
    private:
    unique_ptr<Node> root=nullptr;

    void rotate(unique_ptr<Node>&);
    void rightRot(unique_ptr<Node>&);
    void leftRot(unique_ptr<Node>&);

    int calcHeight(unique_ptr<Node>&);

    void insertHelp(int, unique_ptr<Node>&);
    void remHelp(int, unique_ptr<Node>&);
    void traverseHelp(unique_ptr<Node>&);

    public:
    AVL();

    void insert(int);
    void remove(int);
    void traverse();
};