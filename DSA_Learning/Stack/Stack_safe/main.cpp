#include <iostream>
#include "Stack.hh"

int main(){
    // Create stack with initial value 1 to match original example
    Stack s(1);
    for(int i=2; i<=10; ++i)
        s.push(i);

    std::cout << "Elements (from top to bottom):" << std::endl;
    for(int i=1; i<=10; ++i){
        try{
            std::cout << s.pop() << std::endl;
        }catch(const std::exception &e){
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    return 0;
}
