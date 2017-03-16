/*---------- Class Description -----------
This class extends the transaction class, and is specifically a transaction to
borrow a movie from the store.
*/

#ifndef BORROW_H
#define BORROW_H

#include "transaction.h"
#include "../Movies/movie.h"
#include "../Factories/moviefactory.h"

using namespace std;

class Borrow : public Transaction {

public:

    //method to perform the specifics of this transaction, in this case
    // borrowing a movie from the store
    void doTransaction(BST movies[], HashTable &customers);

    //set the data of Transaction
    bool setData(ifstream& infile, char transactionType);

private:

    //method to get the string representation of this transaction
    string getString() const;

private:

    //title of the movie that this transaction is concerned with
    string movieTitle;

    //movie factory to create the movie that is stored in this transaction,
    // used for retrieving the actual movie from the store
    MovieFactory movieFactory;
};

#endif
