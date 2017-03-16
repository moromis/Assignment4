/*---------- Class Description -----------
This class extends the transaction class, and is specifically a 
transaction to view the inventory of the store.
*/

#ifndef VIEWINVENTORY_H
#define VIEWINVENTORY_H

#include "transaction.h"
#include "../Data Structures/bst.h"

using namespace std;

class ViewInventory : public Transaction {

public:

	//method to perform the specifics of this transaction, in this case
	// displaying the inventory of the store
    void doTransaction(BST movies[], HashTable &customers);

    //set the data of Transaction
	bool setData(ifstream& infile, char transactionType);

private:

    //method to get the string representation of this transaction
	string getString() const;

};

#endif
