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

bool TransactionFactory::createTransaction(char transactionType,
                                           Transaction*& transaction,
                                           ifstream& infile) {

    bool success;

    switch(transactionType){
        case 'I': {

            ViewInventory *tempView = new ViewInventory();
            success = tempView->setData(infile, transactionType);
            transaction = tempView;
            return success;

        }
        case 'B': {

            Borrow *tempBorrow = new Borrow();
            success = tempBorrow->setData(infile, transactionType);
            transaction = tempBorrow;
            return success;

        }
        case 'R': {

            Return *tempReturn = new Return();
            success = tempReturn->setData(infile, transactionType);
            transaction = tempReturn;
            return success;

        }
        case 'H': {

            History *tempHistory = new History();
            success = tempHistory->setData(infile, transactionType);
            transaction = tempHistory;
            return success;

        }
        default: {

            stringstream ss;
            ss << "ERROR: '" << transactionType << "' is not a valid "
                    "transaction type" << endl;
            cout << ss.str();

            //return false to indicate it was an incorrect code
            return false;
        }
    }
}
