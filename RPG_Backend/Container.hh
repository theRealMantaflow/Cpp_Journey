#pragma once
#include "Item.hh"
#include <iostream>
#include <vector>

template <typename T>
class Container{
private:
    std::vector<T> items;

public:
    Container();
    void add(T&&);
    void print();
};