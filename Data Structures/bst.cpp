//
// Created by Kevin on 3/3/2017.
//

#include <iomanip>
#include "bst.h"

//------------------------------------------------------------------------------
/*
 * ~BST
 *
 * Description:
 * Destructor for the BST. Ensures that no memory is leaked and all memory
 * newed by the BST, both the movies in the nodes and the nodes themselves,
 * are deleted and the memory thus freed.
 *
 *
 * Preconditions: The BST must be destroyed
 *
 * Postconditions: The BST has been destroyed and all associated memory has
 * been freed
 */
BST::~BST() {

    //make the BST empty
    makeEmpty(root);

    //dereference the root
    root = nullptr;
}

//------------------------------------------------------------------------------
/*
 * MAKEEMPTY
 *
 * Description:
 * Destructor for the BST. Ensures that no memory is leaked and all memory
 * newed by the BST, both the movies in the nodes and the nodes themselves,
 * are deleted and the memory thus freed.
 *
 *
 * Preconditions: The BST must be destroyed
 *
 * Postconditions: The BST has been destroyed and all associated memory has
 * been freed
 */
void BST::makeEmpty(BST::Node *subtree) {

    //if there's anything to destroy
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

//------------------------------------------------------------------------------
/*
 * INSERT
 *
 * Description:
 * Inserts a movie into the BST. Movies are sorted based on their individual
 * sorting properties, as laid out in their respective operator<, operator>
 * and operator== functions.
 *
 *
 * Preconditions: source exists and needs to be inserted into the BST
 *
 * Postconditions: source has been inserted into the tree, or if something
 * went quite wrong, then an error is printed.
 */
BST::Node* BST::insert(BST::Node* subtree, Movie* source) {

    //if we've reached a leaf, then it's time to insert
    if (subtree == nullptr) {

        //a new node object is allocated and set as the subtree, with source
        // as its data field
        subtree = new Node(source, nullptr, nullptr);

    }
    else if (*source < *subtree->data) {

        //if source is less than this node, then we need to go left (left ==
        // smaller)
        subtree->left = insert(subtree->left, source);

    }
    else if (*source > *subtree->data) {

        //if source is greater than this node, we need to go right
        subtree->right = insert(subtree->right, source);

    }
    else if(*source == *subtree->data){

        //if we find a movie that is the exact same as the movie we're
        // inserting, we're inserting a duplicate, so simply add the one
        // we're going to insert's stock to the one that's already in the BST
        subtree->data->setStock(subtree->data->getStock() + source->getStock());

        //and to avoid leaking memory, delete the movie we were going to insert
        delete source;

    }else{

        //this should never happen
        cout << "ERROR: could not insert " << source->getTitle() << ", please"
                " contact the system administrator" << endl <<
                "for information on why "
                "this movie could not be added to the system" << endl;

    }

    //return the subtree so we don't lose track of any part of the tree
    return subtree;
}

//------------------------------------------------------------------------------
/*
 * RETRIEVE
 *
 * Description:
 * Retrieves a movie from the BST. If target is found, then true is returned
 * and out is pointed at the movie in the BST. Otherwise, return false to
 * indicate that the movie doesn't exist in this BST.
 *
 *
 * Preconditions: target is the movie that we want to find
 *
 * Postconditions: True or false, depending on if the movie was found or not,
 * is returned, and if the movie is found, then out is set to that movie.
 */
bool BST::retrieve(BST::Node* subtree, Movie* target, Movie*& out) const {

    if (subtree == nullptr) {

        //if we've reached a leaf, we didn't find what we were looking for,
        // so simply return false
        return false;

    }
    if (*subtree->data == *target) {

        //if we've found the movie we're looking for, set the out Movie
        // pointer to it and return true to indicate that we found the target
        // Movie
        out = subtree->data;
        return true;
    }
    else if (*target > *subtree->data) {

        //look to the right, as the target is larger than this node's data
        return retrieve(subtree->right, target, out);
    }
    else {

        //look to the left, as the target is smaller than this node's data
        return retrieve(subtree->left, target, out);
    }
}

//------------------------------------------------------------------------------
/*
 * INORDERWALK
 *
 * Description:
 * Walks the BST, printing out data as it goes along. This method uses a
 * stringstream to concatenate all the data into a string.
 *
 *
 * Preconditions: None
 *
 * Postconditions: The BST has been printed to a string and the string has
 * been returned
 */
string BST::inorderWalk(BST::Node* subtree) const{

    //create a stringstream to hold the contents of the inorder walk of this BST
    stringstream ss;

    //if we are not at a leaf
    if (subtree != nullptr) {

        //call the left subtree
        ss << inorderWalk(subtree->left);

        if(!subtree->visited) {

            //print out this movie's title and stock
            ss.setf(ios::left);

            ss << setw(INITIALLENGTH) << " ";

            ss << setw(TITLELENGTH) << subtree->data->getTitle();

            ss << findAllStock(root, subtree->data);

            ss << endl;
        }

        //print out the right subtree
        ss << inorderWalk(subtree->right);
    }

    //return the string output of the stringstream
    return ss.str();
}

//------------------------------------------------------------------------------
/*
 * OPERATOR<<
 *
 * Description:
 * Output operator, simply calls inorderWalk and prints the return of that
 * function.
 *
 *
 * Preconditions: None
 *
 * Postconditions: The BST has been printed.
 */
ostream& operator<<(ostream &stream, const BST& bst){

    //print out the inorder walk of this BST
    stream << bst.inorderWalk();

    //return the output stream
    return stream;
}

//------------------------------------------------------------------------------
/*
 * RESETVISITED
 *
 * Description:
 * Resets all nodes' visited flag in the BST. For use in conjunction with
 * findAllStock, once all movies have been processed.
 *
 *
 * Preconditions: None
 *
 * Postconditions: All visited flags have been reset to false
 */
void BST::resetVisited(Node* subtree) const{

    //if this is not a leaf
    if(subtree != nullptr){

        //reset the visited flag
        subtree->visited = false;

        //run this method on the right and left subtrees
        resetVisited(subtree->right);
        resetVisited(subtree->left);

    }

}

//------------------------------------------------------------------------------
/*
 * FINDALLSTOCK
 *
 * Description:
 * Finds all stock of a given movie. Since classics are stored separate, due
 * to having different major actors, this method is used to find all stock of
 * a given movie based only on title.
 *
 *
 * Preconditions: None
 *
 * Postconditions: An int representing the number of movies in stock under
 * movie's title has been returned
 */
int BST::findAllStock(Node* subtree, Movie*& movie) const {

    if(subtree == nullptr) {

        //if we're at a leaf node, return 0, as there's no data here
        return 0;

    }else if((subtree->data->getTitle() == movie->getTitle()) &&
            !subtree->visited){

        //if the titles match, set the visited flag to true
        subtree->visited = true;

        //and add the stock to the stock of the left and right subtrees from
        // here
        return subtree->data->getStock() +
                (findAllStock(subtree->left, movie) +
                 findAllStock(subtree->right, movie));

    }else {

        //call this method on the left and right subtrees
        return (findAllStock(subtree->left, movie) +
                findAllStock(subtree->right, movie));

    }
}

/*******************************************************************************
 *                          FACADES
 ******************************************************************************/


//------------------------------------------------------------------------------
/*
 * MAKEEMPTY
 *
 * Description:
 * Facade for makeEmpty
 *
 */
void BST::makeEmpty() {

    // facade is created so recursion is able to happen (the function with
    // a parameter can be used for recursion)
    return makeEmpty(root);
}

//------------------------------------------------------------------------------
/*
 * INSERT
 *
 * Description:
 * Facade for insert
 *
 */
void BST::insert(Movie* source) {

    root = insert(root, source);
};

//------------------------------------------------------------------------------
/*
 * RETRIEVE
 *
 * Description:
 * Facade for retrieve
 *
 */
bool BST::retrieve(Movie* target, Movie*& out) const {

    return retrieve(root, target, out);
}

//------------------------------------------------------------------------------
/*
 * INORDERWALK
 *
 * Description:
 * Facade for inorderWalk
 *
 */
string BST::inorderWalk() const{

    string s = inorderWalk(root);
    resetVisited(root);

    return s;
}
