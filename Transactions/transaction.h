/*-------Class description------
A Transaction object is created for all the transactions in the
data4commands.txt file. Each line in the text file represents a transaction.

A ifstream variable in the main function intakes
the text file then passes it to the Store class. The Store class owns a
queue of transactions. The readTransactions function in the store class
works with the TransactionFactory to create a new Transaction object to be
stored in the Store class' "transactions" queue.

The Borrow, Return, and ViewInventory class all extend this class
*/

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "../Data Structures/bst.h"
#include "../Data Structures/hashtable.h"

using namespace std;

class Transaction {

private:
	
	// Indicates, by a user's ID, which Customer completes this transaction
	int customerID;
	
	// Indicates the type of transaction - Borrow, Return, or Inventory
	char transactionType;
	
	char format;
	
	char genre;
	
	// The year the movie was released
	int year;
	
	// the name of a major actor in the movie
	string actor;

    Movie* movie;

public:

    virtual void doTransaction(BST movies[], HashTable &customers) = 0;

	int getCustomerID() const;

	void setCustomerID(int userID);

	char getTransactionType() const;

	void setTransactionType(char transactionType);

	char getFormat() const;

	void setFormat(char format);

	char getGenre() const;

	void setGenre(char genre);

	int getYear() const;

	void setYear(int year);

	string getActor() const;

	void setActor(string actor);

    virtual string getString() const = 0;

	void setMovie(Movie* movie);

    Movie* getMovie() const;

	virtual bool setData(ifstream& infile, char transactionType) = 0;

};

#endif
