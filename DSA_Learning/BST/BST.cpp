#include "BST.hh"

// Constructors and destructor
BST::BST(){}
BST::BST(int){}
BST::~BST(){}

void BST::delHelper(int v, Node*& r) {
    if (r->data==v){
        // For leaf node
        if (!r->left && !r->right){
            delete r;
            r=nullptr;
            return;
        }
        // For either left or right 
        if (r->left && !r->right) {
            auto t=r->left;
            delete r;
            r=t;
            return;
        }
        if(r->right && !r->left){
            auto t=r->right;
            delete r;
            r=t;
            return;
        }
        // For when both left and right are present
        if(r->right && r->left){
            auto temp=r->right;
            
            while(temp->left)
                temp=temp->left;

            r->data=temp->data;

            delHelper(temp->data, r->right);
            return;
        }
    }else{
        if(v<=r->data){
            delHelper(v,r->left);
        }else{
            delHelper(v,r->right);
        }
    }
}
void BST::addHelper(int v, Node*& r){
    if (r==nullptr){
        r=new Node(v);
        return;
    }
    if (v > r->data){
        addHelper(v, r->right);
    }else{
        addHelper(v, r->left);
    }
}
void BST::travHelper(Node*& r){
    if (r==nullptr) {std::cout<<std::endl; return;}
    
    travHelper(r->left);
    std::cout << r->data << " ";
    travHelper(r->right);
}

void BST::add(int v){
    addHelper(v, root);
}
void BST::traverse(){
    travHelper(root);
}
void BST::remove(int value){
    delHelper(value, root);
}