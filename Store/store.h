/*---------- Class Description -----------
This class represents the store itself. It has a Queue of the transactions,
just like a movie store would have receipts for everything that was
borrowed and
returned. The store also has a HashTable of all the customer accounts 
associated with the store. Lastly, the store has a BST to contain 
the inventory of the movies that the store has in stock.

The store class has four methods. The main function creates 
Finally, all transactions that were just read
in are performed via doTransactions.
*/

#include "../Data Structures/hashtable.h"
#include "../Data Structures/queue.h"
#include "../Data Structures/bst.h"
#include "../globals.h"
#include "../Factories/moviefactory.h"
#include "../Movies/classic.h"
#include "../Movies/comedy.h"
#include "../Movies/drama.h"

class Store {

private:

    //queue of all transactions to perform
	Queue transactions;
	
	//hashtable of all customer accounts
	HashTable customers;

	//factory for movies
    MovieFactory movieFactory;

	//BSTs of movies
    BST movies[POSSIBLEMOVIEGENRES];

public:

    //read in the movies from the data file
	void readMovies(ifstream& infile);

    //read in the customers from the data file
    void readCustomers(ifstream& infile);

    //read in the transactions from the data file
	void readTransactions(ifstream& infile);

    //carry out all the transactions in the transactions queue
	void doTransactions();
};
