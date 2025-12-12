#include "Item.hh"

Item::Item(const char* nm, const char* dsc){
    name = new char[strlen(nm)+1];
    desc = new char[strlen(dsc)+1];
    strcpy(name, nm);
    strcpy(desc, dsc);
}

// Movector
Item::Item(Item&& other) noexcept {
    this->name = other.name;
    this->desc = other.desc;
    other.name = nullptr;
    other.desc = nullptr;
}

Item::~Item(){
    delete[] name;
    delete[] desc;
}

// Move assignment
Item& Item::operator=(Item&& other) noexcept{
    if(this != &other){
        delete[] name;
        delete[] desc;
        this->name = other.name;
        this->desc = other.desc;
        other.name = nullptr;
        other.desc = nullptr;
    }
    return *this;
}

char* Item::getName(){return name;}