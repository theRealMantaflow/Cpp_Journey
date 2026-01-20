#include "AVL_Tree.hh"

AVL::AVL(){}

int AVL::calcHeight(std::unique_ptr<Node>& r) {
    if (!r) return 0;

    int hl = calcHeight(r->left);
    int hr = calcHeight(r->right);

    r->balFactor = hl - hr;

    return 1 + std::max(hl, hr);
}

void AVL::rotate(unique_ptr<Node>& r){
    if (!r) return;
    // Left-heavy
    if (r->balFactor>=2){
        // LR
        if (r->left && r->left->balFactor<0)
            leftRot(r->left);

        // LL
        rightRot(r);
        return;
    }
    // Right-heavy
    if (r->balFactor<=-2){
        // RL
        if(r->right && r->right->balFactor>0)
            rightRot(r->right);
        
        // RR
        leftRot(r);
        return;
    }
}

// Right Rotation
void AVL::rightRot(unique_ptr<Node>& r){
    auto t1=move(r->left); // new root
    auto t2=move(t1->right); // right subtree of new root

    t1->right=move(r);
    t1->right->left=move(t2);
    r=move(t1);
    calcHeight(r);
}

// Left Rotation
void AVL::leftRot(unique_ptr<Node>& r){
    auto t1=move(r->right); // new root
    auto t2=move(t1->left); // left subtree of new root

    t1->left=move(r);
    t1->left->right=move(t2);
    r=move(t1);
    calcHeight(r);
}

void AVL::insertHelp(int v, unique_ptr<Node>& r){
    if (!r){
        r=make_unique<Node>(v);
        return;
    }

    if(v <= r->data){
        insertHelp(v, r->left);
    }else {
        insertHelp(v, r->right);
    }
    calcHeight(r);
    rotate(r);
    calcHeight(r);
}
void AVL::remHelp(int v, unique_ptr<Node>& r){
    if (r->data == v) {
        if (!r->left && !r->right){
            r=nullptr;
            return;
        }
        if (r->left && !r->right){
            r=move(r->left);
            return;
        }
        if (!r->left && r->right){
            r=move(r->right);
            return;
        }
        // This can be done in two ways.
        // Swap root with largest element in LST, or smallest element in RST.
        // Both will result in valid balanced Binary trees, albeit with different roots and structure.
        if (r->left && r->right){
            auto t = r->left.get();

            while(t->right)
                t=t->right.get();

            r->data=t->data;

            remHelp(t->data, r->left);
            return;
        }

    } else {
        if (v <= r->data)
            remHelp(v,r->left);
        else
            remHelp(v, r->right);
    }
    if(r){
        calcHeight(r);
        rotate(r);        
    }
}
void AVL::traverseHelp(unique_ptr<Node>& r){
    if(!r) return;
    traverseHelp(r->left);
    if(r==root)
        cout << "|" << r->data << "| ";
    else
        cout << r->data << " ";
    traverseHelp(r->right);
}

void AVL::insert(int v){
    insertHelp(v,root);
}
void AVL::remove(int v){
    remHelp(v, root);
}
void AVL::traverse(){
    traverseHelp(root);
}