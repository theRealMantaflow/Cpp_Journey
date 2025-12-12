#include "Node.hh"
using namespace std;
// class Node{
//     std::string name;
    
// public:
//     Node(std::string n):name(n){}

//     auto getName(){return name;}

//     virtual double getSize()=0;

//     virtual ~Node(){}
// };
Node::Node(const string& nm):name(nm){}
Node::~Node(){}

string Node::getName(){return name;}
