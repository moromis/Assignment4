//
// Created by Kevin on 3/3/2017.
//

#include <iostream>
#include "return.h"

bool Return::setData(ifstream &infile, char transactionType) {

    //set the transaction type
    setTransactionType(transactionType);

    //read in the customer's ID
    int customerID;
    infile >> customerID;
    setCustomerID(customerID);

    //read in the format
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

    //read in the genre
    char genre;
    infile >> genre;
    setGenre(genre);

    //create a partially filled out movie class so we can search the
    // correlating movie BST when we perform the transaction
    Movie* partialMovie = movieFactory.createPartialMovie(genre, infile);
    setMovie(partialMovie);

    return (partialMovie != nullptr);
}


void Return::doTransaction(BST movies[], HashTable &customers) {

    //create a pointer for a movie and a customer, respectively, so we can
    // hold the results of retrieval from the customers hashtable and the
    // movies BST
    Customer* customer;
    Movie* borrowedMovie;
    Movie* movie = getMovie();
    char genre = getGenre();

    //if the customer exists
    if(customers.retrieveCustomer(getCustomerID(), customer)) {

        //and they have borrowed the movie that we want them to return
        if (customer->getBorrowedMovie(movie, borrowedMovie)) {

            Movie* moviePointer;

            if(movies[genre - 'A'].retrieve(borrowedMovie, moviePointer)){

                movieTitle = moviePointer->getTitle();
                movies[genre - 'A'].insert(borrowedMovie);
                customer->insertHistory(getString());

            }else{

                cout << "ERROR: somehow " << *movie << " was checked out, but"
                        " doesn't exist in the store." << endl
                     << *customer << "returned it, but we never owned it in "
                        "the first place." << endl;

            }

        }else{

            cout << "ERROR: " << *customer
                 << " doesn't currently have " << *movie
                    << " checked out" << endl;
        }
    }else{

        cout << "ERROR: " << getCustomerID() << " is not a valid account";
    }
}

string Return::getString() const {

    return "Returned " + movieTitle + ".";
}
