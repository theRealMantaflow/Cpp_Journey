#pragma once
#include "Node.hh"
#include <stdexcept>

class Stack {
private:
    Node* head = nullptr; // head is the top of the stack (O(1) push/pop)
public:
    Stack();
    explicit Stack(int v);
    ~Stack();

    void push(int v);
    int pop();           // throws std::runtime_error if empty
    int peek() const;    // throws std::runtime_error if empty
    bool empty() const noexcept;
};
