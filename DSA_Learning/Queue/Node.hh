#pragma once

struct Node{
    int data;
    Node* next=nullptr;
    Node* prev=nullptr;
    Node();
    Node(int);
};