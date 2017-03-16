//
// Created by Kevin on 3/3/2017.
//

#include <iostream>
#include <iomanip>
#include "drama.h"
#include "../globals.h"


//------------------------------------------------------------------------------
/*
 * DRAMA
 *
 * Description:
 * Constructor for Drama. Sets the genre of this Movie (to D)
 *
 * Preconditions: None
 *
 * Postconditions: None
 */
Drama::Drama(char genre){

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
void Drama::setData(ifstream &infile) {

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
bool Drama::operator==(const Movie &toCompare){

    //if the director and title are the same between this Movie and
    // toCompare, we consider them to be equal
    return (getDirector() == toCompare.getDirector() &&
            getTitle() == toCompare.getTitle());
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
bool Drama::operator>(const Movie &toCompare) {

    if(getDirector() != toCompare.getDirector()){

        //if the director of this Movie and toCompare differ, then return the
        // comparison of the directors of release
        return getDirector() > toCompare.getDirector();

    }else{

        //otherwise, the movies' directors are the same, so compare based
        // on the title of the movie
        return getTitle() > toCompare.getTitle();

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
bool Drama::operator<(const Movie &toCompare) {

    if(getDirector() != toCompare.getDirector()){

        //if the director of this Movie and toCompare differ, then return the
        // comparison of the directors of release
        return getDirector() < toCompare.getDirector();

    }else{

        //otherwise, the movies' directors are the same, so compare based
        // on the title of the movie
        return getTitle() < toCompare.getTitle();

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
void Drama::toString(ostream& stream) const {

    //print out the director and title of this movie
    stream << getDirector() << " " << getTitle();

}
