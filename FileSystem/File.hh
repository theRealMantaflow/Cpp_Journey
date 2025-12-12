#pragma once
#include "Node.hh"

class File:public Node{
private:
    double _size;

public:
    File(std::string, double);
    double getSize();
};