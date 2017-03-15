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

    void doTransaction(BST movies[], HashTable &customers);

	bool setData(ifstream& infile, char transactionType);

	string getString() const;

};

#endif
