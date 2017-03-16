//
// Created by Kevin on 3/3/2017.
//

#include <iomanip>
#include <iostream>
#include "comedy.h"
#include "../globals.h"


//------------------------------------------------------------------------------
/*
 * COMEDY
 *
 * Description:
 * Constructor for Comedy. Sets the genre of this Movie (to F)
 *
 * Preconditions: None
 *
 * Postconditions: None
 */
Comedy::Comedy(char genre){

    //set the genre of the movie given the passed char
    setGenre(genre);
}


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
void Comedy::setData(ifstream &infile) {

    //call the parent class setData to set the initial data fields
    Movie::setData(infile);

    //create a holding variable for the year
    string year;

    //read in year
    getline(infile, year);
    global_functions::trimString(year);
    setYear(stoi(year));
}


//------------------------------------------------------------------------------
/*
 * OPERATOR==
 *
 * Description:
 * Equals operator, checks for equality of this movie with toCompare
 *
 * Preconditions: None
 *
 * Postconditions: A bool indicating whether or not this Movie and toCompare
 * are equal has been returned.
 */
bool Comedy::operator==(const Movie &toCompare){

    //if the title and year are the same between this Movie and
    // toCompare, we consider them to be equal
    return (getTitle() == toCompare.getTitle() &&
            getYear() == toCompare.getYear());
}


//------------------------------------------------------------------------------
/*
 * OPERATOR>
 *
 * Description:
 * Greater than operator. Checks if this Movie is greater than toCompare or not
 *
 * Preconditions: None
 *
 * Postconditions: A bool indicating whether or not this Movie is greater
 * than toCompare has been returned.
 */
bool Comedy::operator>(const Movie& toCompare) {

    if(getTitle() != toCompare.getTitle()){

        //if the title of this Movie and toCompare differ, then return the
        // comparison of the titles of release
        return getTitle() > toCompare.getTitle();

    }else{

        //otherwise, the movies' titles are the same, so compare based
        // on year of release
        return getYear() > toCompare.getYear();

    }
}


//------------------------------------------------------------------------------
/*
 * OPERATOR<
 *
 * Description:
 * Less than operator. Checks if this Movie is less than toCompare or not
 *
 * Preconditions: None
 *
 * Postconditions: A bool indicating whether or not this Movie is less
 * than toCompare has been returned.
 */
bool Comedy::operator<(const Movie &toCompare) {

    if(getTitle() != toCompare.getTitle()){

        //if the title of this Movie and toCompare differ, then return the
        // comparison of the titles of release
        return getTitle() < toCompare.getTitle();

    }else{

        //otherwise, the movies' titles are the same, so compare based
        // on year of release
        return getYear() < toCompare.getYear();

    }
}


//------------------------------------------------------------------------------
/*
 * TOSTRING
 *
 * Description:
 * Prints out this movie.
 *
 * Preconditions: None
 *
 * Postconditions: This movie has been printed.
 */
void Comedy::toString(ostream& stream) const {

    //print the title and year of the movie
    stream << getTitle() << " " << getYear();

}
