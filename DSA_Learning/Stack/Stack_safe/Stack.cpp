#include "Stack.hh"
#include <utility>

Stack::Stack(): head(nullptr) {}

Stack::Stack(int v) {
    head = new Node(v);
}

Stack::~Stack(){
    while(head){
        Node* next = head->next;
        delete head;
        head = next;
    }
}

void Stack::push(int v){
    Node* n = new Node(v);
    n->next = head;
    head = n;
}

int Stack::pop(){
    if(empty())
        throw std::runtime_error("pop from empty stack");
    int v = head->data;
    Node* old = head;
    head = head->next;
    delete old;
    return v;
}

int Stack::peek() const{
    if(empty())
        throw std::runtime_error("peek from empty stack");
    return head->data;
}

bool Stack::empty() const noexcept{
    return head == nullptr;
}
