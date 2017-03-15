//
// Created by Kevin on 3/3/2017.
//

#include <iostream>
#include <iomanip>
#include "viewinventory.h"

bool ViewInventory::setData(ifstream& infile, char transactionType){

    setTransactionType(transactionType);

    return true;

}

void ViewInventory::doTransaction(BST movies[], HashTable &customers) {

    cout << endl << endl;

    for(int i = 0; i < CURRENTMOVIEGENRES; i++){

        cout << HEADERSTRING << endl;
        cout << setw(HEADERLENGTH) << movieGenreNames[i] << endl;
        cout << HEADERSTRING << endl << endl;

        //print out a head line
        cout << HEADERTITLE << HEADERSTOCK << endl << endl;

        //print the given binary tree of movies
        cout << movies[movieGenres[i] - 'A'] << endl;
    }

    cout << endl << endl;
}

string ViewInventory::getString() const {

    return "Viewed store inventory.";
}

