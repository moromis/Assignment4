/*---------- Class Description -----------
This is the main function/driver of the program. It opens the three data
text files associated with the program (data4customers, data4commands,
and data4movies). It assigns three ifstream variables to read the txt files.
The initialized Store object then performs the readCustomers,
readTransactions, and readMovies functions, respectively, to read the contents 
of each of the data files.
*/

#include "../Store/store.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    
    // Creates a new store class - the main class works directly with the Store
    // class - which acts as a manager class.
    Store store;

    // creates three new ifstream variables to read the three txt files
	ifstream customersFile("data4customers.txt");
	ifstream moviesFile("data4movies.txt");
	ifstream transactionsFile("data4commands.txt");

    //send them to the store object to be read into the appropriate data
    //structure
    store.readCustomers(customersFile);
    store.readMovies(moviesFile);
    store.readTransactions(transactionsFile);
    
    //perform all operations
    store.doTransactions();
	
	// end of the main function
	return 0;
	
};