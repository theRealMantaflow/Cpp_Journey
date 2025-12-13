#pragma once

#include <queue>
#include <array>
#include <vector>
#include "Order.hh"

class OrderBook{
    private:
    std::priority_queue<Order> buyBook;
    std::priority_queue<Order, std::vector<Order>, std::greater<Order>> sellBook;

    public:
    OrderBook();

    std::vector< std::array<double, 3> > addOrder(Order&);
};