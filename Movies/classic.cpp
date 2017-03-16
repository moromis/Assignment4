//
// Created by Kevin on 3/3/2017.
//

#include <iostream>
#include <iomanip>
#include "classic.h"
#include "../globals.h"

//------------------------------------------------------------------------------
/*
 * CLASSIC
 *
 * Description:
 * Constructor for Classic. Sets the genre of this Movie (to C)
 *
 * Preconditions: None
 *
 * Postconditions: None
 */
Classic::Classic(char genre) {

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
void Classic::setData(ifstream &infile) {

    //call the parent class setData to set the initial data fields
    Movie::setData(infile);

    //create holding variables for use with the ifstream, since all fields
    // are stored in the parent class and can't be set directly, only through
    // setters
    string firstName;
    string lastName;
    int month;
    string year;

    //get the major actor
    infile >> firstName;
    infile >> lastName;
    setMajorActor(firstName + " " + lastName);

    //read in the month
    infile >> month;
    setMonth(month);

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
bool Classic::operator==(const Movie &toCompare){

    //if the month, year, and major actor are the same between this Movie and
    // toCompare, we consider them to be equal
    return (getMajorActor() == toCompare.getMajorActor() &&
            getYear() == toCompare.getYear() &&
            getMonth() == toCompare.getMonth());
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
bool Classic::operator>(const Movie &toCompare) {

    if(getYear() != toCompare.getYear()){

        //if the year of this Movie and toCompare differ, then return the
        // comparison of the years of release
        return getYear() > toCompare.getYear();

    }else{

        //otherwise, the movies' release years are the same, so compare based
        // on major actor
        return getMajorActor() > toCompare.getMajorActor();

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
bool Classic::operator<(const Movie &toCompare) {

    if(getYear() != toCompare.getYear()){

        //if the year of this Movie and toCompare differ, then return the
        // comparison of the years of release
        return getYear() < toCompare.getYear();

    }else{

        //otherwise, the movies' release years are the same, so compare based
        // on major actor
        return getMajorActor() < toCompare.getMajorActor();

    }
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
Movie& Classic::operator=(Movie& toCopy) {

    //copy the movie, first by calling the parent Movie assignment operator
    Movie::operator=(toCopy);

    //and then setting the month and major actor (the extra variables that a
    // Classic movie has that a normal movie doesn't)
    toCopy.setMonth(getMonth());
    toCopy.setMajorActor(getMajorActor());

    //return the movie
    return toCopy;
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
void Classic::toString(ostream& stream) const{

    //print the month, year, and major actor, the defining features of a
    // classic movie
    stream << getMonth() << " " << getYear() << " " << getMajorActor();

}

