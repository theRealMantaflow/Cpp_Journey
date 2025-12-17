#include "Queue.hh"
#include <iostream>

using namespace std;

int main(){
    Queue q;
    for(int i=1; i<=10; i++){
        q.enqueue(i);
    }

    cout<<"Elememts: "<<endl;
    while(!q.empty()){
        cout<<q.dequeue()<<endl;
    }

    for(int i=10; i<=20; i++){
        q.enqueue(i);
    }

    cout<<"Elememts Again: "<<endl;
    while(!q.empty()){
        cout<<q.dequeue()<<endl;
    }
}