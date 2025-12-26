#pragma once
#include <memory>

struct Node{
    int data;
    std::unique_ptr<Node> left=nullptr;
    std::unique_ptr<Node> right=nullptr;
    Node();
    Node(int);
};