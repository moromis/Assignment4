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

	//the format of the movie
	char format;

    //the genre of the movie
	char genre;

    //the movie used in the transaction, if necessary
    Movie* movie;

public:

~Transaction();

    //method to perform the specifics of this transaction
    virtual void doTransaction(BST movies[], HashTable &customers) = 0;

    virtual bool setData(ifstream& infile, char transactionType) = 0;

    //method to get the string representation of this transaction
    virtual string getString() const = 0;


    //getters and setters
public:

    //getter for the customer's ID
    int getCustomerID() const;

    //setter for the customer's ID
    void setCustomerID(int userID);

    //getter for the transaction type
    char getTransactionType() const;

    //setter for the transaction type
    void setTransactionType(char transactionType);

    //getter for the format of the movie
    char getFormat() const;

    //setter for the format of the movie
    void setFormat(char format);

    //setter for the movie that this transaction may borrow/return
	void setMovie(Movie* movie);

    //getter for the movie that this transaction may borrow/return
    Movie* getMovie() const;


};

#endif
