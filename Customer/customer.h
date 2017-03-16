/*---------- Class Description -----------
This class represents a customer of the store. 
Each customer has two pieces of information.
The object contains two fields. One is "customerID" which represents
the customers ID number. The other is "name" which represnts the name 
of the customer. The Store class has a BST which contains Customer objects.
The BST reads the data4customers.txt file, extracts information about each
customer and creates an Customer object for each customer.
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <fstream>
#include <stack>
#include <queue>
#include "../Data Structures/bst.h"

using namespace std;

class Customer {

    //output operator to print the film
    friend ostream& operator<<(ostream& stream, const Customer& customer);

private:

	//the customer's ID in the system, associated with their account
	int customerID = 0;

    //the customer's first name
    string firstName;

    //the customer's last name
    string lastName;

    //queue to hold a string of the transactions that the customer has
    // performed at the movie store
    stack<string> borrowingHistory;

    //queue of customer's borrowed movies
    queue<Movie*> borrowedMovies;


public:

    //method to set all fields for the customer's account
    bool setData(ifstream &infile);

    //method to borrow a movie from the movie store
    void borrowMovie(Movie*& movie);

    //method to get a borrowed movie from the customer in order to return it
    bool getBorrowedMovie(Movie*& movie, Movie*& returnMovie);

    //method to display the customer's history -- both borrowing and returning
    void displayHistory();

    //insert a transaction into the customer's history
	void insertHistory(string historyToInsert);


	//getters and setters
public:

	// returns the customerID - used to find a customer in the hash table
	int getCustomerID() const;

	// returns the lastName of the customer
	string getFirstName() const;

	// returns the lastName of the customer
	string getLastName() const;
	
};

#endif
