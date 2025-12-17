#include "Queue.hh"

Queue::Queue():head(nullptr),tail(new Node()){
    tail->prev=head;
}
Queue::~Queue(){
    while(!empty()){
        auto t=head->next;
        delete head;
        head=t;
    }
    delete tail;
}

void Queue::enqueue(int v){
    if(empty()){
        head=new Node(v);
        head->next=tail;
        tail->prev=head;
    }else{
        auto t=new Node(v);
        t->prev=tail->prev;
        tail->prev->next=t;
        tail->prev=t;
        t->next=tail;
    }
}

int Queue::dequeue(){
    if(empty()){
        throw std::runtime_error("Empty queue!");
    }

    int v=head->data;
    if(head->next==tail){
        delete head;
        head=nullptr;
        return v;
    }
    auto p=head->next;
    delete head;
    p->prev=nullptr;
    head=p;
    return v;
}

int Queue::peek(){
    if(empty())
        throw std::runtime_error("Empty queue!");
    return head->data;
}

bool Queue::empty(){
    if (head==nullptr) return true;
    else return false;
}