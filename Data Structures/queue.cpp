//
// Created by Kevin on 3/3/2017.
//

#include <sstream>
#include <iostream>
#include "queue.h"

Queue::~Queue(){
    Node* store; // Temp node for deletion

    while (head != nullptr) { // Traverse the list

        store = head; // Prepares to delete head
        head = head->next; // Moves the pointer
        delete store->data;
        store->data = nullptr;
        delete store; // Deletes head
    }

    head = nullptr; // Removes head's pointer
}

void Queue::push(Transaction* transaction) {

    if (head == nullptr) { // First condition, empty list

        head = new Node(transaction, nullptr);
    } else {

        Node* current = head; // Second condition, list of size one

        while (current->next != nullptr) { // Traverse to end of list

            current = current->next; //iterate onto the next node
        }

        current->next = new Node(transaction, nullptr); // Add to end of list
    }
}

Transaction* Queue::pop() {

    Node* store = head;
    Transaction* transaction = nullptr;

    if (head != nullptr) {

        transaction = head->data;
        head = head->next; // iterate through the bankQueue
        delete store;

    }

    return transaction;
}

void Queue::buildQueue(ifstream &infile) {

    //read in the type of transaction
    char transactionType;
    infile >> transactionType;

    while(!infile.eof()) {

        //create a transaction pointer
        Transaction* temp = nullptr;

        //if we can create a transaction (all fields check out and there's no
        // erroneous data)
        if(transactionFactory.createTransaction(transactionType, temp, infile)){

            //push the transaction into the queue
            push(temp);

        }else{

            //we remove the rest of the line
            string store;
            getline(infile, store);

            //and delete the temporary transaction we created if needed
            if(temp != nullptr) delete temp;
        }

        //read in the next transaction type
        infile >> transactionType;

        //if we've hit the end of the file, break
        if(infile.eof()) break;
    }
}

bool Queue::isEmpty() {

    //return if the head of the list is empty, which would indicate that
    // there is nothing in the queue.
    return (head == nullptr);
}
