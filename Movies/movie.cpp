//
// Created by Kevin on 3/10/2017.
//

#include "movie.h"
#include "../globals.h"

#include <iostream>
#include <iomanip>


//------------------------------------------------------------------------------
/*
 * SETDATA
 *
 * Description:
 * Sets the data of this Movie, using the passed ifstream.
 *
 * Preconditions: the infile ifstream is open
 *
 * Postconditions: All data for this movie has been pulled from the ifstream
 */
void Movie::setData(ifstream &infile) {

    //create string to hold each component of the line in the movies text
    // file that denotes this movie
    string store;

    //get the first line
    getline(infile, store, ',');

    //for safety, if we didn't get anything from that line, read until we do
    // have something
    while(store == "") getline(infile, store, ',');

    //and then set what we get as stock
    global_functions::trimString(store);
    setStock(stoi(store));

    //read in director
    getline(infile, store, ',');
    global_functions::trimString(store);
    setDirector(store);

    //read in title
    getline(infile, store, ',');
    global_functions::trimString(store);
    setTitle(store);
}


//------------------------------------------------------------------------------
/*
 * OPERATOR=
 *
 * Description:
 * Copy operator. Copies this Movie into toCopy.
 *
 * Preconditions: None
 *
 * Postconditions: toCopy is == to this Movie
 */
Movie& Movie::operator=(Movie& toCopy) {

    toCopy.setTitle(title);
    toCopy.setYear(year);
    toCopy.setDirector(director);
    toCopy.setGenre(genre);

    return toCopy;
}

//------------------------------------------------------------------------------
/*
 * OPERATOR<<
 *
 * Description:
 * Prints out this movie.
 *
 * Preconditions: None
 *
 * Postconditions: This movie has been printed.
 */
ostream &operator<<(ostream &stream, const Movie &movie) {

    movie.toString(stream);
    return stream;

}



/*******************************************************************************
 *                          Getters and Setters
 ******************************************************************************/


//------------------------------------------------------------------------------
/*
 * GETGENRE
 *
 * Description:
 * Gets the genre of the Movie
 *
 * Preconditions: None
 *
 * Postconditions: the genre of the Movie has been returned
 */
char Movie::getGenre() const {

    return genre;

}

//------------------------------------------------------------------------------
/*
 * SETGENRE
 *
 * Description:
 * Sets the genre of the Movie
 *
 * Preconditions: None
 *
 * Postconditions: the genre of the Movie has been set
 */
void Movie::setGenre(char genre) {

    this->genre = genre;

}


//------------------------------------------------------------------------------
/*
 * GETMAJORACTOR
 *
 * Description:
 * Gets the genre of the Movie
 *
 * Preconditions: None
 *
 * Postconditions: the major actor of the Movie has been returned
 */
string Movie::getMajorActor() const{

    return majorActor;
}


//------------------------------------------------------------------------------
/*
 * SETMAJORACTOR
 *
 * Description:
 * Sets the major actor of the Movie
 *
 * Preconditions: None
 *
 * Postconditions: the major actor of the Movie has been set
 */
void Movie::setMajorActor(string majorActor) {

    this->majorActor = majorActor;
}


//------------------------------------------------------------------------------
/*
 * GETMONTH
 *
 * Description:
 * Gets the month of the Movie
 *
 * Preconditions: None
 *
 * Postconditions: the month of the Movie has been returned
 */
int Movie::getMonth() const{

    return month;
}


//------------------------------------------------------------------------------
/*
 * SETMONTH
 *
 * Description:
 * Sets the month of the Movie
 *
 * Preconditions: None
 *
 * Postconditions: the month of the Movie has been set
 */
void Movie::setMonth(int month) {

    this->month = month;
}


//------------------------------------------------------------------------------
/*
 * GETYEAR
 *
 * Description:
 * Gets the year of the Movie
 *
 * Preconditions: None
 *
 * Postconditions: the year of the Movie has been returned
 */
int Movie::getYear() const{

    return year;
}


//------------------------------------------------------------------------------
/*
 * SETYEAR
 *
 * Description:
 * Sets the year of the Movie
 *
 * Preconditions: None
 *
 * Postconditions: the year of the Movie has been set
 */
void Movie::setYear(int year){

    this->year = year;
}


//------------------------------------------------------------------------------
/*
 * GETTITLE
 *
 * Description:
 * Gets the title of the Movie
 *
 * Preconditions: None
 *
 * Postconditions: the title of the Movie has been returned
 */
string Movie::getTitle() const{

    return title;
}

//------------------------------------------------------------------------------
/*
 * SETTITLE
 *
 * Description:
 * Sets the title of the Movie
 *
 * Preconditions: None
 *
 * Postconditions: the title of the Movie has been set
 */
void Movie::setTitle(string title){

    this->title = title;
}


//------------------------------------------------------------------------------
/*
 * GETSTOCK
 *
 * Description:
 * Gets the stock of the Movie
 *
 * Preconditions: None
 *
 * Postconditions: the stock of the Movie has been returned
 */
int Movie::getStock() const{

    return stock;
}

//------------------------------------------------------------------------------
/*
 * SETSTOCK
 *
 * Description:
 * Sets the stock of the Movie
 *
 * Preconditions: None
 *
 * Postconditions: the stock of the Movie has been set
 */
void Movie::setStock(int stock){

    this->stock = stock;
}


//------------------------------------------------------------------------------
/*
 * GETDIRECTOR
 *
 * Description:
 * Gets the director of the Movie
 *
 * Preconditions: None
 *
 * Postconditions: the director of the Movie has been returned
 */
string Movie::getDirector() const{

    return director;
}


//------------------------------------------------------------------------------
/*
 * SETDIRECTOR
 *
 * Description:
 * Sets the director of the Movie
 *
 * Preconditions: None
 *
 * Postconditions: the director of the Movie has been set
 */
void Movie::setDirector(string director){

    this->director = director;
}