//
// Created by Kevin on 3/3/2017.
//

#include <sstream>
#include <iostream>
#include "borrow.h"

bool Borrow::setData(ifstream& infile, char transactionType){

    //set the transaction type
    setTransactionType(transactionType);

    //set the customer ID
    int customerID;
    infile >> customerID;
    setCustomerID(customerID);

    //set the format
    char format;
    infile >> format;
    setFormat(format);

    //if we don't have a DVD, then it's an improper format, since only DVDs
    // are held at the store currently. print an error message and return false.
    if(format != 'D'){
        cout << "ERROR: '" << format << "' is not a currently allowed movie "
                "format" << endl;

        return false;
    }

    //set the genre of the movie
    char genre;
    infile >> genre;
    setGenre(genre);

    //create a partially filled out movie class so we can search the
    // correlating movie BST when we perform the transaction
    Movie* partialMovie = movieFactory.createPartialMovie(genre, infile);
    setMovie(partialMovie);

    return (partialMovie != nullptr);
}

void Borrow::doTransaction(BST movies[], HashTable &customers) {

    //create a pointer for a movie and a customer, respectively, so we can
    // hold the results of retrieval from the customers hashtable and the
    // movies BST
    Movie* stockedMovie;
    Customer* customer;
    Movie* movie = getMovie();
    char genre = getGenre();

    //if the customer exists
    if(customers.retrieveCustomer(getCustomerID(), customer)) {

        //if we can find the movie
        if (movies[genre - 'A'].retrieve(movie, stockedMovie)) {

            //and copies of the movie are in stock
            if (stockedMovie->getStock() > 0) {

                //let the customer borrow the movie -- the borrowMovie method
                // makes a copy of the movie with stock == 1,  and then we
                // reduce the stock of the store's copy of the movie by 1
                customer->borrowMovie(movie);
                stockedMovie->setStock(stockedMovie->getStock() - 1);
                movieTitle = stockedMovie->getTitle();

                //insert the operation into the customer's history, since it
                // was completed
                customer->insertHistory(getString());

                //otherwise print out one of the following errors, depending
                // on what went wrong
            } else {

                cout << "ERROR: " << "there are no copies of " <<
                     *movie << " currently in stock " << endl;
            }

        } else {

            cout << "ERROR: " << *movie << " is not in stock" << endl;
        }
    }else{

        cout << "ERROR: " << getCustomerID()
             << " is not a valid account" << endl;
    }
}

string Borrow::getString() const {

    return "Borrowed " + movieTitle + ".";

}
