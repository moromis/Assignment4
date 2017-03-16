//
// Created by Kevin on 3/3/2017.
//

#include "store.h"

using namespace std;


//------------------------------------------------------------------------------
/*
 * READMOVIES
 *
 * Description:
 * Reads in all movies from the passed ifstream
 *
 * Preconditions: the infile ifstream is open
 *
 * Postconditions: All movies have been read in from the ifstream
 */
void Store::readMovies(ifstream& infile) {

    //if the passed ifstream isn't open, then print an error and close the
    // program
    if (!infile) {
        cout << "ERROR: Movies file could not be opened." << endl;
        exit(-1);
    }

    //create holding variables for the genre
    char genre;
    string genreString;

    //read in the first movie genre
    getline(infile, genreString, ',');
    genre = genreString[0];

    //while there's things to read
    while(!infile.eof()) {

        //create a movie pointer which we'll pass to the movie factory
        Movie* temp = nullptr;

        //if we are able to create a movie using the ifstream (all data for
        // all fields in the movie are filled without errors)
        if(movieFactory.createMovie(infile, genre, temp)){

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

    //once we're done with the file, close it
    infile.close();

}


//------------------------------------------------------------------------------
/*
 * READCUSTOMERS
 *
 * Description:
 * Reads in all customers from the passed ifstream
 *
 * Preconditions: the infile ifstream is open
 *
 * Postconditions: All customers have been read in from the ifstream
 */
void Store::readCustomers(ifstream& infile) {

    //if the passed ifstream isn't open, then print an error and close the
    // program
    if (!infile) {
        cout << "ERROR: Customers file could not be opened." << endl;
        exit(-1);
    }

    //let the hashtable build itself given the ifstream
    customers.buildHashTable(infile);

    //once we're done with the file, close it
    infile.close();

}


//------------------------------------------------------------------------------
/*
 * READTRANSACTIONS
 *
 * Description:
 * Reads in all transactions from the passed ifstream
 *
 * Preconditions: the infile ifstream is open
 *
 * Postconditions: All transactions have been read in from the ifstream
 */
void Store::readTransactions(ifstream& infile) {

    //if the passed ifstream isn't open, then print an error and close the
    // program
    if (!infile) {
        cout << "ERROR: Commands file could not be opened." << endl;
        exit(-1);
    }

    //let the queue build itself given the ifstream
    transactions.buildQueue(infile);

    //once we're done with the file, close it
    infile.close();
}


//------------------------------------------------------------------------------
/*
 * DOTRANSACTIONS
 *
 * Description:
 * Performs all Transactions in the transactions queue. Pops one transaction
 * out from the queue at a time, and then calls doTransaction on it.
 *
 * Preconditions: None
 *
 * Postconditions: All Transactions have been popped from the transaction
 * queue, and doTransaction has been called on all of them.
 */
void Store::doTransactions() {

    //while there's transactions to do
    while(!transactions.empty()) {

        //pop a transaction
        Transaction* transaction;
        transaction = transactions.pop();

        //and do the transaction
        transaction->doTransaction(movies, customers);
    }

}