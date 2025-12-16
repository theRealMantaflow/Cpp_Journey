#include "Stack.hh"
#include <iostream>
int main(){
    Stack s;
    for(int i=1; i<=10; i++)
        s.push(i);

    std::cout << "Elements" << std::endl;
    while(!s.empty())
        std::cout << s.pop() << " " << std::endl;
        
    for(int i=10; i<=20; i++)
        s.push(i);
        
    std::cout << "Elements again:" << std::endl;
    while(!s.empty())
        std::cout << s.pop() << " " << std::endl;
}