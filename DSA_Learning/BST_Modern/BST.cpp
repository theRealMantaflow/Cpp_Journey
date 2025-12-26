#include "BST.hh"

// Constructors 
BST::BST(){}
BST::BST(int){}

void BST::delHelper(int v, std::unique_ptr<Node>& r) {
    if (r->data==v){
        // For leaf node
        if (!r->left && !r->right){
            r=nullptr;
            return;
        }
        // For either left or right 
        if (r->left && !r->right) {
            r=std::move(r->left);
            return;
        }
        if(r->right && !r->left){
            r=std::move(r->right);
            return;
        }
        // For when both left and right are present
        if(r->right && r->left){
            auto temp=r->right.get();
            
            while(temp->left)
                temp=temp->left.get();

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
void BST::addHelper(int v, std::unique_ptr<Node>& r){
    if (r==nullptr){
        r = std::make_unique<Node>(v);
        return;
    }
    if (v > r->data){
        addHelper(v, r->right);
    }else{
        addHelper(v, r->left);
    }
}
void BST::travHelper(std::unique_ptr<Node>& r){
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