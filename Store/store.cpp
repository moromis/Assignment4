//
// Created by Kevin on 3/3/2017.
//

#include "store.h"

using namespace std;

void Store::readMovies(ifstream& infile) {

    if (!infile) {
        cout << "ERROR: Movies file could not be opened." << endl;
        exit(-1);
    }

    char genre;
    string genreString;

    //read in the first movie genre
    getline(infile, genreString, ',');
    genre = genreString[0];

    //while there's things to read
    while(!infile.eof()) {

        //create a movie pointer which we'll pass to the movie factory
        Movie* temp = nullptr;

        bool success;

        //try to instantiate a movie
        success = movieFactory.createMovie(infile, genre, temp);
        if(success){

            //if we successfully create a movie object, then insert it into
            // the correct BST
            movies[genre - 'A'].insert(temp);

        }else{

            //print an error, the movie wasn't of a proper genre
            stringstream ss;
            ss << "ERROR: '" << genre << "' is not a valid genre" << endl;
            cout << ss.str();
        }

        //read in a new movie genre
        getline(infile, genreString, ',');
        genre = genreString[0];

        //if we reach the end of the file (we just read in genre and it would
        // be == ' ') then break out of this loop
        if(infile.eof()) break;
    }

    infile.close();

}

void Store::readCustomers(ifstream& infile) {

    if (!infile) {
        cout << "ERROR: Customers file could not be opened." << endl;
        exit(-1);
    }

    //let the hashtable build itself given the ifstream
    customers.buildHashTable(infile);

    infile.close();

}

void Store::readTransactions(ifstream& infile) {

    if (!infile) {
        cout << "ERROR: Commands file could not be opened." << endl;
        exit(-1);
    }

    //let the queue build itself given the ifstream
    transactions.buildQueue(infile);

    infile.close();
}

void Store::doTransactions() {

    //while there's transactions to do
    while(!transactions.isEmpty()) {

        //pop a transaction
        Transaction* transaction;
        transaction = transactions.pop();

        //and do the transaction
        transaction->doTransaction(movies, customers);
    }

}