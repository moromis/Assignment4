//
// Created by Kevin on 3/3/2017.
//

#include <iostream>
#include "history.h"

bool History::setData(ifstream &infile, char transactionType) {

    setTransactionType(transactionType);

    int store;
    infile >> store;
    setCustomerID(store);

    return true;
}

void History::doTransaction(BST movies[], HashTable &customers) {

    Customer* customer;

    if(customers.retrieveCustomer(getCustomerID(), customer)){

        customerName = customer->getFirstName() + " " + customer->getLastName();
        customer->displayHistory();

    }else{

        cout << "ERROR: " << *customer << " does not have an account";
    }
}

string History::getString() const {

    stringstream ss;
    ss << "Displayed ";
    ss << customerName;
    ss << "'s transaction history.";

    return ss.str();
}
