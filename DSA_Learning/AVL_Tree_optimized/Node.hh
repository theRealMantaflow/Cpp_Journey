#pragma once
#include <memory>

using namespace std;

struct Node{
    int data;
    int height=0;
    int balFactor;
    unique_ptr<Node> left=nullptr;
    unique_ptr<Node> right=nullptr;

    Node();
    Node(int);
};