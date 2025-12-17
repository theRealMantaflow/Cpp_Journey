#pragma once
#include "Node.hh"
#include <stdexcept>

class Queue{
    Node* head;
    Node* tail;

    public:
    Queue();
    ~Queue();

    void enqueue(int v);
    int dequeue();
    int peek();
    bool empty();
};