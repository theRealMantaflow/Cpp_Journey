#pragma once
#include "Node.hh"
#include <iostream>
#include <fstream>

class AVL {
    private:
    unique_ptr<Node> root=nullptr;

    void rotate(unique_ptr<Node>&);
    void rightRot(unique_ptr<Node>&);
    void leftRot(unique_ptr<Node>&);

    void calcHeight(unique_ptr<Node>&);

    void insertHelp(int, unique_ptr<Node>&);
    void remHelp(int, unique_ptr<Node>&);
    void traverseHelp(unique_ptr<Node>&);
    void asciiHelp(int, const unique_ptr<Node>&);
    void emitDot(const unique_ptr<Node>&, ostream& out);
    
    public:
    AVL();
    
    void insert(int);
    void remove(int);
    void traverse();
    void asciiPrint();
    void saveDots(const string&);
};