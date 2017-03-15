//
// Created by Kevin on 3/3/2017.
//

#include <stack>
#include <iostream>
#include "customer.h"

using namespace std;


//------------------------------------------------------------------------------
/*
 * GRAPHM
 *
 * Description:
 * Initialize the graph. defaults all values in the C and T tables to infinity.
 *
 *
 * Preconditions: A graph is desired.
 *
 * Postconditions: The graph now exists,
 */
bool Customer::setData(ifstream &infile) {

    //read in the customer's ID
    infile >> customerID;

    if(customerID >= 0 && customerID <= 9999){

        //read in the customer's last name followed by their first name
        infile >> lastName;
        infile >> firstName;

        return true;

    }else{

        //print an error, since we received an invalid ID
        cout << "ERROR: " << customerID
             << " is not a valid customer ID." << endl;

        return false;

    }
}


//------------------------------------------------------------------------------
/*
 * GRAPHM
 *
 * Description:
 * Initialize the graph. defaults all values in the C and T tables to infinity.
 *
 *
 * Preconditions: A graph is desired.
 *
 * Postconditions: The graph now exists,
 */
void Customer::displayHistory() {

    stack<string> stack;
    string temp;

    cout << endl;

    cout << firstName << " " << lastName << "'s borrowing"
            " history:" << endl;

    while(!borrowingHistory.empty()){

        temp = borrowingHistory.front();
        borrowingHistory.pop();

        cout << " * " << temp << endl;

        stack.push(temp);
    }

    while(!stack.empty()){

        temp = stack.top();

        borrowingHistory.push(temp);
        stack.pop();
    }

    cout << endl;

}


//------------------------------------------------------------------------------
/*
 * GRAPHM
 *
 * Description:
 * Initialize the graph. defaults all values in the C and T tables to infinity.
 *
 *
 * Preconditions: A graph is desired.
 *
 * Postconditions: The graph now exists,
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
 * GRAPHM
 *
 * Description:
 * Initialize the graph. defaults all values in the C and T tables to infinity.
 *
 *
 * Preconditions: A graph is desired.
 *
 * Postconditions: The graph now exists,
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
 * GRAPHM
 *
 * Description:
 * Initialize the graph. defaults all values in the C and T tables to infinity.
 *
 *
 * Preconditions: A graph is desired.
 *
 * Postconditions: The graph now exists,
 */
void Customer::insertHistory(string historyToInsert) {

    borrowingHistory.push(historyToInsert);

}


//------------------------------------------------------------------------------
/*
 * GRAPHM
 *
 * Description:
 * Initialize the graph. defaults all values in the C and T tables to infinity.
 *
 *
 * Preconditions: A graph is desired.
 *
 * Postconditions: The graph now exists,
 */
ostream& operator<<(ostream& stream, const Customer& customer){

    stream << customer.getFirstName() << " " << customer.getLastName()
           << " (ID: " << customer.getCustomerID() << ")";

    return stream;
}


/*******************************************************************************
 *                          Getters and Setters
 ******************************************************************************/

int Customer::getCustomerID() const{
    return customerID;
}

string Customer::getFirstName() const{
    return firstName;
}

string Customer::getLastName() const{
    return lastName;
}