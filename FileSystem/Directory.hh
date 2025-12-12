#include "File.hh"
#include <vector>
#include <memory>

class Directory:public Node{

private:
    std::vector<std::unique_ptr<Node>> contents;

public:
    Directory(std::string);

    void add(Node*);

    const std::vector<std::unique_ptr<Node>>& getContent() const&;

    double getSize();
};