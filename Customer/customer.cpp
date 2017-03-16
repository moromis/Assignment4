//
// Created by Kevin on 3/3/2017.
//

#include <stack>
#include <iostream>
#include "customer.h"

using namespace std;


//------------------------------------------------------------------------------
/*
 * SETDATA
 *
 * Description:
 * Using an ifstream file set all data for the customer. This is expected to
 * be in the format of the customer's ID, then the customer's last name, then
 * their first name.
 *
 * If we receive an invalid ID, that is, between 0 and 9999, then we read in
 * all the data. But if we don't get an ID within that range, then we throw
 * an error.
 *
 *
 * Preconditions: infile should be open.
 *
 * Postconditions: the customer's fields are filled and true has been
 * returned, or an error has been printed if the ID was incorrect, and we
 * return false to indicate that the customer should not be instantiated.
 */
bool Customer::setData(ifstream &infile) {

    //read in the customer's ID
    infile >> customerID;

    if(customerID >= 0){

        //read in the customer's last name followed by their first name
        infile >> lastName;
        infile >> firstName;

        //return true to indicate that all fields were successfully populated
        return true;

    }else{

        //print an error, since we received an invalid ID
        cout << "ERROR: " << customerID
             << " is not a valid customer ID." << endl;

        //return false to indicate that the data given to populate the
        // Customer was not valid
        return false;

    }
}


//------------------------------------------------------------------------------
/*
 * DISPLAYHISTORY
 *
 * Description:
 * Displays the customer's borrowing (and also return) history. Since the
 * borrowing history is stored in a queue, we pop it from the queue into a
 * stack, essentially flipping it, and print as it comes out of the queue.
 *
 * This prints the first thing inserted into the queue, the first transaction
 * that the customer performed, first. Once we're done printing the borrowing
 * history, we pop all elements off the stack and back into the queue.
 *
 *
 * Preconditions: None
 *
 * Postconditions: The customer's history has been printed, and if they have
 * none then a message indicating the lack of transactions is printed.
 */
void Customer::displayHistory() {

    //create a queue and string to hold history strings as they're taken out
    // of the queue
    queue<string> queue;
    string temp;

    cout << endl;

    //print a heading line
    cout << firstName << " " << lastName << "'s borrowing"
            " history:" << endl;

    //if there's things to print, aka the Customer has performed transactions
    if(!borrowingHistory.empty()) {

        //while there's transactions to print
        while (!borrowingHistory.empty()) {

            //pop the transaction
            temp = borrowingHistory.top();
            borrowingHistory.pop();

            //print the transaction
            cout << " * " << temp << endl;

            //push it onto the queue
            queue.push(temp);
        }

        //once we've printed all the transactions, put them back in the queue
        while (!queue.empty()) {

            temp = queue.front();

            borrowingHistory.push(temp);
            queue.pop();
        }

        cout << endl;

    }else{

        //if the customer has nothing in their history, just print an "error"
        cout << " * " << firstName << " " << lastName
             << " has not visited the store yet." << endl << endl;

    }

}


//------------------------------------------------------------------------------
/*
 * BORROWMOVIE
 *
 * Description:
 * Borrows a movie from the store, given a reference to that movie. This
 * method accomplishes this by making a copy of the movie object, and
 * inserting it into the borrowedMovies queue with a stock of 1.
 *
 *
 * Preconditions: movie exists, aka the pointer points to a real movie
 *
 * Postconditions: The movie has been inserted into the customer's borrowed
 * movies queue
 */
void Customer::borrowMovie(Movie*& movie) {

    //create a copy of the movie and borrow one stock of it
    Movie* copy = movie;
    copy->setStock(1);

    //insert it into the customer's borrowed movies
    borrowedMovies.push(copy);
}


//------------------------------------------------------------------------------
/*
 * GETBORROWEDMOVIE
 *
 * Description:
 * This method finds a movie in the customer's borrowedMovies queue. The
 * return of this method indicates whether or not the movie was found, and if
 * it was then returnMovie will be == to that movie, and it will have been
 * removed from borrowedMovies.
 *
 *
 * Preconditions: movie exists, aka the pointer points to a real movie
 *
 * Postconditions: If the movie is in the customer's borrowedMovies queue,
 * then true is returned and returnMovie is == to movie. Otherwise, false is
 * returned to indicate that the customer does not currently have the
 * indicated movie borrowed.
 */
bool Customer::getBorrowedMovie(Movie*& movie, Movie*& returnMovie) {

    //create a stack to store contents of the borrowedMovies queue as we pop
    // them, as well as a movie pointer to store things as we move them back
    // and forth between the stack and queue, to maintain data consistency
    stack<Movie*> stack;
    Movie* store;

    while(!borrowedMovies.empty()) {

        //look at the front Movie, the first borrowed
        store = borrowedMovies.front();

        //if we find the movie that the user should return
        if (*movie == *store) {

            //we found the movie we're looking for, reference it via
            // returnMovie so it can be accessed in the calling environment
            returnMovie = store;

            //pop off the movie, removing it from the customer's borrowed movies
            borrowedMovies.pop();

            //put all elements back into the queue
            while(!stack.empty()){

                store = stack.top();
                borrowedMovies.push(store);
                stack.pop();

            }

            return true;

        } else {

            //otherwise, since we haven't found it, take the movies
            //out of the queue and put it onto a stack
            store = borrowedMovies.front();
            stack.push(store);
            borrowedMovies.pop();

        }
    }

    //put all elements back into the queue
    while(!stack.empty()){

        store = stack.top();
        borrowedMovies.push(store);
        stack.pop();

    }

    return false;

}


//------------------------------------------------------------------------------
/*
 * INSERTHISTORY
 *
 * Description:
 * Inserts a string into the customer's borrowingHistory queue.
 *
 *
 * Preconditions: None
 *
 * Postconditions: A string has been inserted into the historyToInsert
 */
void Customer::insertHistory(string historyToInsert) {

    //push the string into the borrowingHistory queue
    borrowingHistory.push(historyToInsert);

}


//------------------------------------------------------------------------------
/*
 * OPERATOR<<
 *
 * Description:
 * The output operator outputs the customer, their first name, last name, and
 * ID, to the passed stream.
 *
 *
 * Preconditions: None
 *
 * Postconditions: The customer has been printed, first name then last name
 * then ID
 */
ostream& operator<<(ostream& stream, const Customer& customer){

    //print out the Customer's first and last name, followed by their ID
    stream << customer.getFirstName() << " " << customer.getLastName()
           << " (ID: " << customer.getCustomerID() << ")";

    return stream;
}


/*******************************************************************************
 *                          Getters and Setters
 ******************************************************************************/


//------------------------------------------------------------------------------
/*
 * GETCUSTOMERID
 *
 * Description:
 * Gets the customer's ID
 *
 *
 * Preconditions: None
 *
 * Postconditions: the Customer's ID has been returned
 */
int Customer::getCustomerID() const{
    return customerID;
}


//------------------------------------------------------------------------------
/*
 * GETFIRSTNAME
 *
 * Description:
 * Gets the customer's first name
 *
 *
 * Preconditions: None
 *
 * Postconditions: the Customer's first name has been returned
 */
string Customer::getFirstName() const{
    return firstName;
}


//------------------------------------------------------------------------------
/*
 * GETLASTNAME
 *
 * Description:
 * Gets the customer's last name
 *
 *
 * Preconditions: None
 *
 * Postconditions: the Customer's last name has been returned
 */
string Customer::getLastName() const{
    return lastName;
}