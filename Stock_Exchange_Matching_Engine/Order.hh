#pragma once

#include <string>

enum class OrderType{
    BUY,
    SELL
};
struct Order{
    public:
    OrderType ord;
    std::string ticker;
    float shares;
    double price;
    
    public:
    Order(OrderType, std::string, float, double);

    bool operator>(const Order&) const;
    bool operator<(const Order&) const;
    bool operator>=(const Order&) const;
    bool operator<=(const Order&) const;
};
