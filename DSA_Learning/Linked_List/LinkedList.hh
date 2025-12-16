#pragma once
#include "Node.hh"
#include <iostream>

class LinkedList{
    protected:
    Node *head;
    Node *tail;

    public:
    LinkedList(int);
    ~LinkedList();

    virtual void insert(int);
    virtual void remove(int);
    void print();

};
