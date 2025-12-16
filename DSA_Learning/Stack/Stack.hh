#include "Node.hh"
#include <stdexcept>
class Stack{
    Node *head;
public:
    Stack();
    Stack(int);
    ~Stack();
    
    void push(int);
    int pop();
    int peek();
    bool empty() noexcept;
};