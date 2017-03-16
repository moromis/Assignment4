//
// Created by Kevin on 3/3/2017.
//

#include <iostream>
#include <iomanip>
#include "viewinventory.h"


//------------------------------------------------------------------------------
/*
 * SETDATA
 *
 * Description:
 * Sets the data of this Transaction, using the passed ifstream.
 *
 * Preconditions: the infile ifstream is open
 *
 * Postconditions: All data for this Transaction has been pulled from the
 * ifstream
 */
bool ViewInventory::setData(ifstream& infile, char transactionType){

    //set the transaction type
    setTransactionType(transactionType);

    //return true, this method is always successful
    return true;

}


//------------------------------------------------------------------------------
/*
 * DOTRANSACTION
 *
 * Description:
 * Performs the specific details of this Transaction.
 *
 * In this case we simply print out all BSTs that exist in the movies array.
 *
 * Preconditions: None
 *
 * Postconditions: All of the store's inventory has been printed out.
 */
void ViewInventory::doTransaction(BST movies[], HashTable &customers) {

    //print some returns to separate the inventory from the previous output
    cout << endl << endl;

    //print out all movie inventories
    for(int i = 0; i < CURRENTMOVIEGENRES; i++){

        cout << HEADERSTRING << endl;
        cout << setw(HEADERLENGTH) << movieGenreNames[i] << endl;
        cout << HEADERSTRING << endl << endl;

        //print out a head line
        cout << HEADERTITLE << HEADERSTOCK << endl << endl;

        //print the given binary tree of movies
        cout << movies[movieGenres[i] - 'A'] << endl;
    }

    //print more returns to separate what comes after the inventory
    cout << endl << endl;
}


//------------------------------------------------------------------------------
/*
 * GETSTRING
 *
 * Description:
 * Gets a string representation of the Transaction.
 *
 * Preconditions: None
 *
 * Postconditions: A string representation of the Transaction has been returned
 */
string ViewInventory::getString() const {

    //print the string representing this Transaction
    return "Viewed store inventory.";
}

