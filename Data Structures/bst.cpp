//
// Created by Kevin on 3/3/2017.
//

#include <iomanip>
#include "bst.h"


BST::~BST() {

    //make the BST empty
    makeEmpty(root);

    //dereference the root
    root = nullptr;
}

void BST::makeEmpty() {

    // facade is created so recursion is able to happen (the function with
    // a parameter can be used for recursion)
    return makeEmpty(root);
}

void BST::makeEmpty(BST::Node *subtree) {

    if (subtree != nullptr) {

        // if the subtree isn't empty then go through the tree and delete
        // what is there
        makeEmpty(subtree->right);	// traverse the right side of the tree
        makeEmpty(subtree->left);	// traverse the left side of the tree

        //delete the data from this node
        delete subtree->data;
        subtree->data = nullptr;

        //delete the node itself
        delete subtree;
    }
}

void BST::insert(Movie* source) {

    root = insert(root, source);
};


BST::Node* BST::insert(BST::Node* subtree, Movie* source) {

    if (subtree == nullptr) {

        // base case - a new node object is allocated and set as the subtree
        subtree = new Node(source, nullptr, nullptr);

    }
    else if (*source < *subtree->data) {

        subtree->left = insert(subtree->left, source);

    }
    else if (*source > *subtree->data) {

        subtree->right = insert(subtree->right, source);

    }
    else if(*source == *subtree->data){

        subtree->data->setStock(subtree->data->getStock() + source->getStock());

    }else{

        cout << "ERROR: could not insert " << source->getTitle() << ", please"
                " contact the system administrator" << endl <<
                "for information on why "
                "this movie could not be added to the system" << endl;

    }

    return subtree;
}


bool BST::retrieve(Movie* target, Movie*& out) const {

    return retrieve(root, target, out);
}

bool BST::retrieve(BST::Node* subtree, Movie* target, Movie*& out) const {

    if (subtree == nullptr) {

        return false;
    }
    if (*subtree->data == *target) {

        //if we've found the movie we're looking for
        out = subtree->data;
        return true;
    }
    else if (*target > *subtree->data) {

        return retrieve(subtree->right, target, out);
    }
    else {

        return retrieve(subtree->left, target, out);
    }
}

string BST::inorderWalk() const{

    string s = inorderWalk(root);
    resetVisited(root);

    return s;
}

string BST::inorderWalk(BST::Node* subtree) const{

    string retVal = "";
    stringstream ss;
    if (subtree != nullptr) {

        ss << inorderWalk(subtree->left);

        if(!subtree->visited) {

            ss.setf(ios::left);

            ss << setw(INITIALLENGTH) << " ";

            ss << setw(TITLELENGTH) << subtree->data->getTitle();

            ss << findAllStock(root, subtree->data);

            ss << endl;
        }

        ss << inorderWalk(subtree->right);
    }

    return ss.str();
}

ostream& operator<<(ostream &stream, const BST& bst){

    stream << bst.inorderWalk();

    return stream;
}

void BST::resetVisited(Node* subtree) const{

    if(subtree != nullptr){

        subtree->visited = false;
        resetVisited(subtree->right);
        resetVisited(subtree->left);

    }

}

int BST::findAllStock(Node* subtree, Movie*& movie) const {

    if(subtree == nullptr) {

        return 0;

    }else if((subtree->data->getTitle() == movie->getTitle()) &&
            !subtree->visited){

        subtree->visited = true;

        return subtree->data->getStock() +
                (findAllStock(subtree->left, movie) +
                 findAllStock(subtree->right, movie));

    }else {

        return (findAllStock(subtree->left, movie) +
                findAllStock(subtree->right, movie));

    }
}


