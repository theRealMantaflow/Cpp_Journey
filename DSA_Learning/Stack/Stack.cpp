#include "Stack.hh"

Stack::Stack(){
    head=nullptr;
}
Stack::Stack(int v){
    head=new Node(v);
}
Stack::~Stack(){
    while(!empty()){
        auto nxt=head->next;
        delete head;
        head=nxt;
    }
}

void Stack::push(int v){
    auto t=new Node(v);
    t->next=head;
    head=t;
}

int Stack::pop(){
    if(empty()){
        throw std::runtime_error("EMPTY STACK");
    }
    auto t=head->data;
    auto old=head;

    head=head->next;

    delete old;

    return t;
}

int Stack::peek(){
    if(!empty()){
        return head->data;
    }else{
        throw std::runtime_error("EMPTY STACK");
    }
}

bool Stack::empty() noexcept {
    return head==nullptr;
}