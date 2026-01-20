#include "AVL_Tree.hh"

int main(){
    AVL av;
    for(int i=10; i>=1; --i)
        av.insert(i);
    av.traverse();
    cout<<endl;
    
    av.remove(7);
    av.traverse();
    cout<<endl;

    av.insert(7);
    av.traverse();
 }