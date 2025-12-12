#pragma once

#include <string>

class Node{
private:
    std::string name;

public:
    explicit Node(const std::string& name);
    virtual ~Node();

    virtual double getSize() = 0;
    std::string getName();
};