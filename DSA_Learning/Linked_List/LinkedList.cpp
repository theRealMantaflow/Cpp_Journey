#include "LinkedList.hh"

LinkedList::LinkedList(int v){
    head=new Node(v);
    tail=head;
    tail->next=nullptr;
}

LinkedList::~LinkedList(){
    auto current=head;
    while(current!=nullptr){
        auto next=current->next;
        delete current;
        current=next;
    }
}

void LinkedList::insert(int v) {
    auto k=new Node(v);
    tail->next=k;
    tail=tail->next;
    tail->next=nullptr;
}

void LinkedList::remove(int v){

    if (head==nullptr){
        return;
    }

    if(head->data==v && head!=tail){
        auto p=head->next;
        delete head;
        head = p;
        return;
    }else if(head==tail && head->data == v){
        delete head;
        head=tail=nullptr;
        return;
    }
    
    auto k=head;
    while(k->next!=nullptr){
        if(k->next->data==v){
            if (k->next==tail){
                tail=k;
                delete tail->next;
                tail->next = nullptr;
            }else{
                auto p=k->next->next;
                delete k->next;
                k->next = p;
            }
            break;
        }
        k=k->next;
    }
}

void LinkedList::print(){
    auto k=head;
    while(k!=nullptr) {
        std::cout << k->data << " ";
        k=k->next;
    }
    std::cout << "NULL" << std::endl;
}