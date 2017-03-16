/*---------- Class Description -----------
This class represents a hash table of the customers that the store has on
record. The hashtable is implemented using an array of linked lists -- i.e.
an open hashtable.
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "../Customer/customer.h"
#include "../globals.h"

using namespace std;

class HashTable {


    /*
     * This defines the nodes that the HashTable contains. Each node has a
     * Customer and a pointer to the next node
     */
    struct node{

        Customer* data;
        node* next;

        node(Customer* c, node* n) :
                data(c), next(n) {};
    };

private:
    
    //array to hold the linked lists which we hash customers into
	node* array[MAXHASHSIZE];

public:

    //default constructor
    HashTable();

    //destructor
    ~HashTable();

    //retrieves a customer from the table
	bool retrieveCustomer(int customerID, Customer*& foundCustomer);

    //inserts a customer into the table
    void insert(Customer *customer);

    //method to build the hashtable given a ifstream
	void buildHashTable(ifstream &infile);

private:

    //hashes a customer based on their ID
	int hash(int customerID);
};

#endif
