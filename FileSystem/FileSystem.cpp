#include <iostream>
#include "Directory.hh"

using namespace std;

void iterateHierarchy(Directory* dirs){
    cout << dirs->getName() << " (" << dirs->getSize() << ")\n|" << endl;
    for(const auto& i : dirs->getContent()){
        cout << i->getName() << " (" << i->getSize() << ")\n|" << endl;
    }
}

int main(){
    // Folders:
    Directory* root = new Directory("root");
    Directory* usr = new Directory("User");
    // Files: 
    File* r1 = new File("config.txt", 10);
    File* u1 = new File("profile.jpg", 200);

    usr->add(u1);
    root->add(r1);
    root->add(usr);

    // Print the hierarchy of root
    cout << "\nroot Folder: " << endl;
    iterateHierarchy(root);

    // Print the hierarchy of User
    cout << "\nUser Folder: " << endl;
    iterateHierarchy(usr);
    
    delete root;
    return 0;
}