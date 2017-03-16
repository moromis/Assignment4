//
// Created by Kevin on 3/3/2017.
//

#include <iostream>
#include "return.h"


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

    //create a partially filled out movie class so we can search the
    // correlating movie BST when we perform the transaction
    Movie* partialMovie = movieFactory.createPartialMovie(genre, infile);
    setMovie(partialMovie);

    return (partialMovie != nullptr);
}


//------------------------------------------------------------------------------
/*
 * DOTRANSACTION
 *
 * Description:
 * Performs the specific details of this Transaction.
 *
 * In this case we retrieve the desired Customer and if they have borrowed
 * the indicated Movie, we take it away from them, and insert it back into
 * the store's stock.
 *
 * Preconditions: None
 *
 * Postconditions: If the Customer and Movie were found, then the Customer
 * now has one less copy of the movie, and the store has one more copy in stock.
 */
void Return::doTransaction(BST movies[], HashTable& customers) {

    //create a pointer for a movie and a customer, respectively, so we can
    // hold the results of retrieval from the customers hashtable and the
    // movies BST
    Customer* customer;
    Movie* borrowedMovie;
    Movie* movie = getMovie();
    char genre = movie->getGenre();

    //if the customer exists
    if(customers.retrieveCustomer(getCustomerID(), customer)) {

        //and they have borrowed the movie that we want them to return
        if (customer->getBorrowedMovie(movie, borrowedMovie)) {

            //create a pointer for retrieving the movie from the movies BST
            // array
            Movie* moviePointer;

            //if we can find the movie -- to see if the store owns it
            if(movies[genre - 'A'].retrieve(borrowedMovie, moviePointer)){

                //insert the movie that we got from the customer into the
                // store inventory... since it has a stock of 1, it will
                // simply increment the stock of the movie in the store by 1
                movies[genre - 'A'].insert(borrowedMovie);

                //store the title of the movie for use in getString
                movieTitle = moviePointer->getTitle();

                //insert the operation into the customer's history, since it
                // was completed
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
string Return::getString() const {

    //print the string representing this Transaction
    return "Returned " + movieTitle + ".";
}
