//
// Created by Kevin on 3/3/2017.
//

#include <sstream>
#include <iostream>
#include "queue.h"


//------------------------------------------------------------------------------
/*
 * ~QUEUE
 *
 * Description:
 * Destructor. Frees all dynamically allocated memory occupied by this queue.
 *
 *
 * Preconditions: None
 *
 * Postconditions: All memory allocated by this queue has been freed.
 */
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


//------------------------------------------------------------------------------
/*
 * PUSH
 *
 * Description:
 * Pushes a transaction into the queue.
 *
 *
 * Preconditions: transaction is the Transaction we want to push into the queue.
 *
 * Postconditions: transaction has been inserted into the back of the queue.
 */
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

//------------------------------------------------------------------------------
/*
 * POP
 *
 * Description:
 * Pops a transaction from the front of the queue and returns it to the
 * calling function.
 *
 *
 * Preconditions: None
 *
 * Postconditions: A transaction has been returned from the front of the
 * queue if there is anything in the queue to begin with.
 */
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

//------------------------------------------------------------------------------
/*
 * ISEMPTY
 *
 * Description:
 * Returns a bool indicating whether the queue is empty or not
 *
 *
 * Preconditions: None
 *
 * Postconditions: A bool has been returned to indicate whether the queue is
 * empty or not.
 */
bool Queue::empty() {

    //return if the head of the list is empty, which would indicate that
    // there is nothing in the queue.
    return (head == nullptr);
}

//------------------------------------------------------------------------------
/*
 * BUILDQUEUE
 *
 * Description:
 * Given an ifstream build a queue of transactions. As long as all data used
 * to create the transaction is correct and formatted properly, then the
 * transaction is pushed into the back of the queue.
 *
 *
 * Preconditions: None
 *
 * Postconditions: All data from infile has been read in and transactions
 * from each line have been created and inserted into the queue, if the data
 * is correct.
 */
void Queue::buildQueue(ifstream &infile) {

    //read in the type of transaction
    char transactionType;
    infile >> transactionType;

    //while there's data to read
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
