//
// Created by Kevin on 3/3/2017.
//

#include "hashtable.h"


//------------------------------------------------------------------------------
/*
 * HASHTABLE
 *
 * Description:
 * Constructor for Hashtable. Sets all array indeces to nullptr since I'm
 * simply superstitious.
 *
 *
 * Preconditions: None
 *
 * Postconditions: Hashtable is instantiated, all indeces == nullptr
 */
HashTable::HashTable(){

    //null all indeces in the array
    for(int i = 0; i < MAXHASHSIZE; i++){
        array[i] = nullptr;
    }

}


//------------------------------------------------------------------------------
/*
 * ~HASHTABLE
 *
 * Description:
 * Destructor function, frees all dynamically allocated memory
 *
 *
 * Preconditions: None
 *
 * Postconditions: All memory used by this hashtable is freed and no memory
 * leaks may come from this data structure.
 */
HashTable::~HashTable(){

    //create a current to hold nodes in the lists of the hashtable
    node* current;

    //go through the whole array
    for(int i = 0; i < MAXHASHSIZE; i++){

        //for each list, traverse the whole list
        while(array[i] != nullptr){

            //capture the node at the front and move the head of the list
            // forward
            current = array[i];
            array[i] = array[i]->next;

            //delete the data of the node
            delete current->data;
            current->data = nullptr;

            //delete the node itself
            delete current;

        }

        //dereference the bucket from the list to prevent dangling references
        array[i] = nullptr;
    }
}

//------------------------------------------------------------------------------
/*
 * RETRIEVECUSTOMER
 *
 * Description:
 * Retrieves a customer from the HashTable. First, the customerID is hashed
 * to find the proper bucket, and then the linked list in that bucket is
 * walked to see if the customer exists in that list.
 *
 *
 * Preconditions: customerID indicates the customer that is desired to be found
 *
 * Postconditions: If the customer was found, foundCustomer has been set to
 * the customer found in the hashtable, and true has been returned.
 * Otherwise, false has been returned.
 */
bool HashTable::retrieveCustomer(int customerID, Customer*& foundCustomer) {

    //hash the ID of the customer
    int IDHash = hash(customerID);

    //point to the list in the specified bucket defined by the hashed ID integer
    node* current = array[IDHash];

    //traverse the whole list
    while (current != nullptr){

        //if we find the desired customer which we want to retrieve
        if(current->data->getCustomerID() == customerID){

            //point the foundCustomer pointer at it and return true to
            // indicate that we found them
            foundCustomer = current->data;
            return true;

        }else{

            //otherwise we haven't yet found the correct Customer, so move
            // forward in the list
            current = current->next;
        }
    }

    //we didn't find the customer, return false
    return false;
}

//------------------------------------------------------------------------------
/*
 * INSERT
 *
 * Description:
 * Inserts a customer into the hashtable.
 *
 *
 * Preconditions: customer is the Customer we want to insert into the hashtable
 *
 * Postconditions:
 */
void HashTable::insert(Customer* customer){

    //hash the customer's ID
    int IDHash = hash(customer->getCustomerID());

    //store the head node of the bucket
    node* current = array[IDHash];
    node* previous = nullptr;

    while(current != nullptr){

        if(customer->getCustomerID() == current->data->getCustomerID()){

            cout << "ERROR: duplicate ID " << customer->getCustomerID()
                 << " not inserted." << endl;

            delete customer;

            return;

        }else{

            previous = current;
            current = current->next;
        }
    }

    if(previous == nullptr) {

        //put the customer in at the front of the list, pointing to the previous
        // head of the list
        current->next = new node(customer, nullptr);

    }else{

        //put the customer in at the front of the list, pointing to the previous
        // head of the list
        previous->next = new node(customer, nullptr);

    }
}

//------------------------------------------------------------------------------
/*
 * HASH
 *
 * Description:
 * Hashes an integer, used for inserting into the hashtable
 *
 *
 * Preconditions: None
 *
 * Postconditions: Returns the hashed integer
 */
int HashTable::hash(int customerID) {

    //hash based on the maximum hash size, the size of the array. This is a
    // large prime number
    return customerID % MAXHASHSIZE;

}

//------------------------------------------------------------------------------
/*
 * BUILDHASHTABLE
 *
 * Description:
 * Reads in all Customers from the passed ifstream, inserting them into the
 * hashtable if all data read from the ifstream is properly formatted.
 *
 *
 * Preconditions: None
 *
 * Postconditions: All data from the infile ifstream has been read and all
 * correct Customers have been created and inserted into the hashtable.
 */
void HashTable::buildHashTable(ifstream& infile) {

    //while the file has data to read
    while(!infile.eof()) {

        //create a new customer
        Customer* temp = new Customer;

        //if we are able to create a new Customer, aka all the data is correct
        if(temp->setData(infile)){

            //and we haven't reached the end of file (no reason to insert a
            // non-existent customer
            if(!infile.eof()) {

                //insert the customer
                insert(temp);

            }else{

                //this is not good data, delete it
                delete temp;

            }
        }else{

            //we were unable to create a customer, delete this malformed
            // abomination from hell
            delete temp;

        }
    }
}
