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

private:

	string getString() const;

private:

    string customerName;

public:

	void doTransaction(BST movies[], HashTable &customers);

	bool setData(ifstream& infile, char transactionType);

};

#endif
