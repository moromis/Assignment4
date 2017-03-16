//
// Created by Kevin on 3/3/2017.
//

#include <iostream>
#include "transactionfactory.h"
#include "../Transactions/viewinventory.h"
#include "../Transactions/borrow.h"
#include "../Transactions/return.h"
#include "../Transactions/history.h"
#include "error.h"


//------------------------------------------------------------------------------
/*
 * CREATETRANSACTION
 *
 * Description:
 * Creates a Transaction, based on the passed transactionType char. If the
 * char is one of the currently accepted transaction type's (currently I, H,
 * B, or R), then the correct class is instantiated and bound to transaction.
 *
 *
 * Preconditions: A Transaction needs to be created.
 *
 * Postconditions: If the transactionType char is of a correct type (I, H, B,
 * or R currently), then a new Transaction is created and bound to
 * transaction. True is returned in this case. Otherwise, false is returned
 * and an error message is printed.
 */
bool TransactionFactory::createTransaction(char transactionType,
                                           Transaction*& transaction,
                                           ifstream& infile) {

    //bool to store the success of the creation of the Transaction
    bool success;

    switch(transactionType){
        case 'I': {

            //received I, create a ViewInventory Transaction
            transaction = new ViewInventory();
            success = transaction->setData(infile, transactionType);
            return success;

        }
        case 'B': {

            //received B, create a Borrow Transaction
            transaction = new Borrow();
            success = transaction->setData(infile, transactionType);
            return success;

        }
        case 'R': {

            //received R, create a Return Transaction
            transaction = new Return();
            success = transaction->setData(infile, transactionType);
            return success;

        }
        case 'H': {

            //received H, create a History Transaction
            transaction = new History();
            success = transaction->setData(infile, transactionType);
            return success;

        }
        default: {

            //we didn't receive a valid transaction type (currently only H,
            // R, I, and B are accepted) so print an error message and return
            // false to indicate that we were unable to create a Transaction
            // object
            stringstream ss;
            ss << "ERROR: '" << transactionType << "' is not a valid "
                    "transaction type" << endl;
            cout << ss.str();

            //return false to indicate it was an incorrect code
            return false;
        }
    }
}
