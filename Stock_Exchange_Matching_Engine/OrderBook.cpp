#include "OrderBook.hh"
#include <iostream>

OrderBook::OrderBook(){
    buyBook = std::priority_queue<Order>();
    sellBook = std::priority_queue<Order, std::vector<Order>, std::greater<Order>>();
}

std::vector< std::array<double, 3> > OrderBook::addOrder(Order& od){
    std::vector< std::array<double, 3> > outr;

    if (od.ord == OrderType::BUY){

        while (!sellBook.empty() && od >= sellBook.top() && od.shares > 0){

            if (sellBook.top().shares <= od.shares){

                od.shares-=sellBook.top().shares;
                
                // number of shares sold, original price, bought at
                outr.push_back({sellBook.top().shares, sellBook.top().price, od.price});

                sellBook.pop();

            }else { // here (sellBook.top().shares > od.shares)

                auto t=sellBook.top();

                sellBook.pop();
                t.shares-=od.shares;
                sellBook.push(t);
                
                outr.push_back({od.shares, sellBook.top().price, od.price});
                od.shares = 0;
            }
        }

        if (od.shares > 0){
            buyBook.push(od);
        }

        return outr;

    // For sell orders
    }else{
        while (!buyBook.empty() && buyBook.top() >= od && od.shares > 0){

            if (buyBook.top().shares <= od.shares){
                
                od.shares-=buyBook.top().shares;
                
                // number of shares bought, sold at, asking price
                outr.push_back({buyBook.top().shares, buyBook.top().price, od.price});

                buyBook.pop();

            }else { // here (buyBook.top().shares > od.shares)

                auto t=buyBook.top();

                buyBook.pop();
                t.shares-=od.shares;
                buyBook.push(t);
                
                outr.push_back({od.shares, buyBook.top().price, od.price});
                od.shares = 0;
            }
        }

        if (od.shares > 0){
            sellBook.push(od);
        }
        return outr;
    }
}