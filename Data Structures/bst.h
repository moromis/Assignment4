/*---------- Class Description -----------
This class represents a binary search tree (BST) and the functions
represent the common actions of a BST such as a insertion and retrieval
of a node with the BST. This BST class holds Movie objects and the Store class
is what holds this BST class. In other words, the nodes in this class hold Movie
objects and a pointer to two other nodes (one on left side and right side of
the node in the tree)
The Movie class and Store class are also defined in this program.
The Store class owns one BST and the BST owns one to as many Movie objects.
The BST is ordered according the Movie objects' release year
*/

#ifndef BST_H
#define BST_H

#include <fstream>
#include <sstream>
#include <iostream>
#include "../globals.h"
#include "../Movies/movie.h"

using namespace std;

class BST {

    //output operator
    friend ostream& operator<<(ostream& stream, const BST& bst);

    /*
    This defines the nodes that the BST contains. Each BST contains
    a Movie pointer and two pointers that point to two different nodes
    */
    struct Node{
        Movie* data;
        Node* left = nullptr;
        Node* right = nullptr;
        bool visited = false;

        Node(Movie* d, Node* l, Node* r) :
                data(d), left(l), right(r){};
    };

private:

    /*
     * Helper Functions
     */

    //finds all stock of a movie
    int findAllStock(Node* subtree, Movie*& movie) const;

    //resets the visited flag of all nodes in the subtree
    void resetVisited(Node* subtree) const;

public:

    //destructor
    ~BST();

    /*
    Intakes an Movie object and places it into the BST. The BST is ordered
    according the Movie's "year" field value
    */
    void insert(Movie* source);

    /*
    The retrieve function intakes two parameters.The first one is of type Movie.
    The function searches through the BST to see if there is a node whose's 
    Movie's lastName value matches the lastName value of the
    Movie object passed through the parameter. 
    The second parameter is a pointer to an Movie object. 
    If the Movie object is found, the second parameter will
    point to that Movie object. If the Movie object is found within the BST, 
    the function will return true - otherwise it will return false.
    */
    bool retrieve(Movie* target, Movie*& out) const;


    /*
    This functions goes through the BST and deletes every Movie object
    and sets the subtree to NULL
    */
    void makeEmpty();

    //inorder walk function to print out the BST
    string inorderWalk() const;

private:

    /*
    Helper function for the insert function
    */
    Node* insert(Node* subtree, Movie* source);

    /*
    Helper function for the retrieve function
    */
    bool retrieve(Node* subtree, Movie* target, Movie*& out) const;

    /*
    Helper function for the makeEmpty function
    */
    void makeEmpty(Node* subtree);

    /*
    This variable represents the subtree of the tree - the first Movie object
    that is inserted into the tree will be set to this variable
    */
    Node* root = nullptr;

    //Helper function for inorder walk
    string inorderWalk(Node* subtree) const;

};

#endif
