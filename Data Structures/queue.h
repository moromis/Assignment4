/*---------- Class Description -----------
This class is an implementation of a queue. It has three methods, one to push
an element into the queue, another to pop an element from the opposite end of
the queue, and the last to build the queue given a ifstream.

It must be kept in mind that the queue is FIFO, and is implemented using
a linked list with limited access.
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "../Transactions/transaction.h"
#include "../Factories/transactionfactory.h"
#include <fstream>

using namespace std;

class Queue {

    struct Node {        	// the node in a linked list
            Transaction* data;          	// pointer to actual data
            Node* next;	// pointer to the next node (the node that holds the next transaction)

            Node(Transaction* d, Node* n) : data(d), next(n) {}

            Node() {
                next = nullptr;
            }
    };

private:
	TransactionFactory transactionFactory;

    Node* head = nullptr;

public:

    ~Queue();

    //push onto the top of the queue
	void push(Transaction* transaction);
	
	//pop the last element, the first inserted, from the bottom of the queue.
	Transaction* pop();

    bool empty();

    //build the queue given an ifstream
	void buildQueue(ifstream& infile);
};

#endif
