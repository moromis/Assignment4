//
// Created by Kevin on 3/3/2017.
//

#include <iostream>
#include <iomanip>
#include "classic.h"
#include "../globals.h"

Classic::Classic(char genre) {

    setGenre(genre);

}

void Classic::setData(ifstream &infile) {

    Movie::setData(infile);

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

bool Classic::operator==(const Movie &toCompare){

    return (getMajorActor() == toCompare.getMajorActor() &&
            getYear() == toCompare.getYear() &&
            getMonth() == getMonth());
}

bool Classic::operator>(const Movie &toCompare) {

    if(getYear() != toCompare.getYear()){

        return getYear() > toCompare.getYear();

    }else{

        return getMajorActor() > toCompare.getMajorActor();

    }
}

bool Classic::operator<(const Movie &toCompare) {

    if(getYear() != toCompare.getYear()){

        return getYear() < toCompare.getYear();

    }else{

        return getMajorActor() < toCompare.getMajorActor();

    }
}

Movie& Classic::operator=(Movie &toCopy) {

    Movie::operator=(toCopy);
    toCopy.setMonth(getMonth());
    toCopy.setMajorActor(getMajorActor());

    return toCopy;
}

void Classic::toString(ostream& stream) const{

    stream << getMonth() << " " << getYear() << " " << getMajorActor();

}
