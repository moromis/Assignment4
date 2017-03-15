//
// Created by Kevin on 3/3/2017.
//

#include "hashtable.h"

HashTable::HashTable(){
    for(int i = 0; i < MAXHASHSIZE; i++){
        array[i] = nullptr;
    }
}

HashTable::~HashTable(){

    node* current;

    for(int i = 0; i < MAXHASHSIZE; i++){
        while(array[i] != nullptr){
            current = array[i];
            array[i] = array[i]->next;
            delete current;
        }
    }
}

bool HashTable::retrieveCustomer(int customerID, Customer*& foundCustomer) {

    int IDHash = hash(customerID);

    node* current = array[IDHash];

    while (current != nullptr){
        if(current->data->getCustomerID() == customerID){

            foundCustomer = current->data;
            return true;

        }else{

            current = current->next;
        }
    }

    return false;
}

void HashTable::insert(Customer *customer){

    int IDHash = hash(customer->getCustomerID());

    node* store = array[IDHash];

    array[IDHash] = new node(customer, store);

}

int HashTable::hash(int customerID) {
    return customerID % 100;
}

void HashTable::buildHashTable(ifstream &infile) {

    while(!infile.eof()) {

        Customer* temp = new Customer;

        if(temp->setData(infile)){

            if(!infile.eof()) {

                insert(temp);

            }else{

                delete temp;

            }
        }else{

            delete temp;

        }
    }
}
