//
// Created by Kevin on 3/3/2017.
//

#include <iostream>
#include "history.h"


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
bool History::setData(ifstream &infile, char transactionType) {

    //set the transaction type
    setTransactionType(transactionType);

    //set the customer ID
    int customerID;
    infile >> customerID;
    setCustomerID(customerID);

    //there is no way for the method to fail, so we return true
    return true;
}


//------------------------------------------------------------------------------
/*
 * DOTRANSACTION
 *
 * Description:
 * Performs the specific details of this Transaction.
 *
 * In this case we retrieve the desired Customer and display their
 * transaction history, using the Customer's displayHistory method.
 *
 * Preconditions: None
 *
 * Postconditions: If the Customer was found, their transaction history has
 * been printed, otherwise an error has been printed.
 */
void History::doTransaction(BST movies[], HashTable& customers) {

    //create a temporary pointer to a Customer
    Customer* customer;

    //retrieve the customer that this Transaction requires
    if(customers.retrieveCustomer(getCustomerID(), customer)){

        //if we successfully retrieve the customer then store their name for
        // getString purposes
        customerName = customer->getFirstName() + " " + customer->getLastName();

        //display the customer's history
        customer->displayHistory();

    }else{

        //otherwise we weren't able to find the customer, print an error
        cout << "ERROR: " << *customer << " does not have an account";
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
string History::getString() const {

    //print out the string representation of this Transaction
    stringstream ss;
    ss << "Displayed ";
    ss << customerName;
    ss << "'s transaction history.";

    return ss.str();
}
