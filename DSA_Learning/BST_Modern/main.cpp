#include "BST.hh"

using namespace std;

int main(){
    BST bt;
    bt.add(50);
    bt.add(30);
    bt.add(20);
    bt.add(40);
    bt.add(70);
    bt.add(60);
    bt.add(80);

    bt.traverse();

    bt.remove(20);
    bt.traverse();
    bt.remove(30);
    bt.traverse();
    bt.remove(50);
    bt.traverse();
}