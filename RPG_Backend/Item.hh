#pragma once

#include <cstring>
class Item{
private:
    char *name, *desc;

public:
    Item(const char*, const char*);
    Item(Item&&) noexcept;
    Item(Item&)=delete; // Copyctor delete
    ~Item();
    
    Item& operator=(Item&&) noexcept; // Move assignment

    Item& operator=(Item&)=delete; // Copy assignment delete

    char* getName();
};