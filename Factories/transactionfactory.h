/*---------- Class Description -----------
This class is a factory for creating transactions. Since transactions
are an action, this is a proper use of the factory design pattern.
*/

#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include <fstream>
#include "../Transactions/transaction.h"

using namespace std;

class TransactionFactory {

public:

	// creates a transaction object of the requested type
	bool createTransaction(char transactionType, Transaction*& transaction,
						   ifstream& infile);
};

#endif
