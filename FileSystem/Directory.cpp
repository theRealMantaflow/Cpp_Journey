#include "Directory.hh"

Directory::Directory(std::string name):Node(name){}

void Directory::add(Node* n){
    if(!n->getName().empty())
        contents.push_back(std::unique_ptr<Node>(n));
    else
        throw "Invalid File/Folder";
}

const std::vector<std::unique_ptr<Node>>& Directory::getContent() const& {return contents;}

double Directory::getSize(){
    double siz=0;
    for(const auto& sz:contents){
        siz+=sz->getSize();
    }
    return siz;
}