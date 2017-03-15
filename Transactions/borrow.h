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

    void doTransaction(BST movies[], HashTable &customers);

    bool setData(ifstream& infile, char transactionType);

    string getString() const;

private:

    string movieTitle;

    MovieFactory movieFactory;
};

#endif
