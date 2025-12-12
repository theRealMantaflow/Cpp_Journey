#include "Container.hh"


template <typename T>
Container<T>::Container(){}
// template class Container<Item>;

template <typename T>
void Container<T>::add(T&& item){
    items.push_back(std::move(item));
}
// template class Container<Item>;

template <typename T>
void Container<T>::print(){
    for(auto &i:items){
        std::cout << i.getName() << " ";
    }std::cout<<std::endl;
}
template class Container<Item>;