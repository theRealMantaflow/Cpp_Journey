#include "Container.hh"
#include "Item.hh"

using namespace std;

int main(){
    Container<Item> backpack;
    Item sword("Sword", "A sharp blade.");
    backpack.add(move(sword));
    backpack.print();
}