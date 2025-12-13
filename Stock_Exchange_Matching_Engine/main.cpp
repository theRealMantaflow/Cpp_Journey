#include <iostream>
#include "OrderBook.hh"

using namespace std;

int main(){
    OrderBook ob_apple;

    Order s1(OrderType::SELL, "AAPPL", 10, 100);
    Order s2(OrderType::SELL, "AAPPL", 8, 105);
    Order s3(OrderType::SELL, "AAPPL", 2, 106);

    Order b1(OrderType::BUY, "AAPPL", 20, 105);

    ob_apple.addOrder(s1);
    ob_apple.addOrder(s2);
    ob_apple.addOrder(s3);

    vector<array<double,3>> buy_ops = ob_apple.addOrder(b1);

    int k=1;
    for(const auto& i : buy_ops){
        cout << "Buy operation " << k <<endl;
        cout << "Shares: " << i[0] << endl;
        cout << "Bought at: " << i[1] << endl;
        cout << "Asking price: " << i[2] << endl << endl;
        k++;
    }
}