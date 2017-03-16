/*---------- Class Description -----------
This class extends the transaction class, and is specifically a 
transaction to display the history of transactions of the store.
*/

#ifndef HISTORY_H
#define HISTORY_H

#include "transaction.h"
#include <fstream>

using namespace std;

class History : public Transaction {

public:

    //method to perform the specifics of this transaction, in this case
    // displaying a customer's borrowing history
    void doTransaction(BST movies[], HashTable &customers);

    //set the data of Transaction
    bool setData(ifstream& infile, char transactionType);

private:

    //method to get the string representation of this transaction
    string getString() const;

private:

    //name of customer that we want to display the history of
    string customerName;

};

#endif
