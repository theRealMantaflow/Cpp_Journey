#include "Order.hh"

Order::Order(OrderType ot, std::string tkr, float shr, double prc):
ord(ot),ticker(tkr),shares(shr),price(prc) {}

bool Order::operator>(const Order& other) const {
    if(this != &other){
        return this->price>other.price;
    }else{
        return false;
    }
}

bool Order::operator<(const Order& other) const {
    if(this != &other){
        return this->price<other.price;
    }else{
        return false;
    }
}

bool Order::operator>=(const Order& other) const {
    if(this != &other){
        return this->price>=other.price;
    }else{ 
        return true;
    }
}

bool Order::operator<=(const Order& other) const {
    if(this != &other){
        return this->price<=other.price;
    }else{
        return true;
    }
}