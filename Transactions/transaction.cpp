//
// Created by Kevin on 3/3/2017.
//

#include "transaction.h"


//------------------------------------------------------------------------------
/*
 * DECONSTRUCTOR
 *
 * Description:
 * Deallocates all memory assoicated with this transaction, which is just the
 * movie object
 *
 * Preconditions: None
 *
 * Postconditions: All dynamically allocated memory in this Transaction class
 * has been freed, resulting in no memory leaks
 */
Transaction::~Transaction(){

    if(movie != nullptr) delete movie;

}

//------------------------------------------------------------------------------
/*
 * GETCUSTOMERID
 *
 * Description:
 * Gets the customerID of the Transaction
 *
 * Preconditions: None
 *
 * Postconditions: the customerID of the Transaction has been returned
 */
int Transaction::getCustomerID() const {

    return customerID;

}


//------------------------------------------------------------------------------
/*
 * SETCUSTOMERID
 *
 * Description:
 * Sets the customerID of the Transaction
 *
 * Preconditions: None
 *
 * Postconditions: the customerID of the Transaction has been set
 */
void Transaction::setCustomerID(int userID) {

    this->customerID = userID;

}


//------------------------------------------------------------------------------
/*
 * GETTRANSACTIONTYPE
 *
 * Description:
 * Gets the transaction type of the Transaction
 *
 * Preconditions: None
 *
 * Postconditions: the transaction type of the Transaction has been returned
 */
char Transaction::getTransactionType() const{

    return transactionType;

}


//------------------------------------------------------------------------------
/*
 * SETTRANSACTIONTYPE
 *
 * Description:
 * Sets the transaction type of the Transaction
 *
 * Preconditions: None
 *
 * Postconditions: the transaction type of the Transaction has been set
 */
void Transaction::setTransactionType(char transactionType) {

    this->transactionType = transactionType;

}


//------------------------------------------------------------------------------
/*
 * GETFORMAT
 *
 * Description:
 * Gets the format of the Transaction
 *
 * Preconditions: None
 *
 * Postconditions: the format of the Transaction has been returned
 */
char Transaction::getFormat() const{

    return format;

}


//------------------------------------------------------------------------------
/*
 * SETFORMAT
 *
 * Description:
 * Sets the format of the Transaction
 *
 * Preconditions: None
 *
 * Postconditions: the format of the Transaction has been set
 */
void Transaction::setFormat(char format) {

    this->format = format;

}

//------------------------------------------------------------------------------
/*
 * GETMOVIE
 *
 * Description:
 * Gets the movie of the Transaction
 *
 * Preconditions: None
 *
 * Postconditions: the movie of the Transaction has been returned
 */
Movie* Transaction::getMovie() const {

    return movie;

}

//------------------------------------------------------------------------------
/*
 * SETMOVIE
 *
 * Description:
 * Sets the movie of the Transaction
 *
 * Preconditions: None
 *
 * Postconditions: the movie of the Transaction has been set
 */
void Transaction::setMovie(Movie *movie) {
    this->movie = movie;
}

