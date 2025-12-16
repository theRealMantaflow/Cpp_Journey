#include "LinkedList.hh"

int main(){
    LinkedList ll(10);
    for(int i=9; i>0; i--){
        ll.insert(i);
    }
    ll.print();
    // ll.remove(1);
    // ll.print();
    // ll.insert(11);
    // ll.print();
}