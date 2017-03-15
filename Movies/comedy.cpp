//
// Created by Kevin on 3/3/2017.
//

#include <iomanip>
#include <iostream>
#include "comedy.h"
#include "../globals.h"

Comedy::Comedy(char genre){

    setGenre(genre);
}

void Comedy::setData(ifstream &infile) {

    Movie::setData(infile);

    string store;

    //read in year
    getline(infile, store);
    global_functions::trimString(store);
    setYear(stoi(store));
}

bool Comedy::operator==(const Movie &toCompare){

    return (getTitle() == toCompare.getTitle() &&
            getYear() == toCompare.getYear());
}

bool Comedy::operator>(const Movie& toCompare) {

    if(getTitle() != toCompare.getTitle()){

        return getTitle() > toCompare.getTitle();

    }else{

        return getYear() > toCompare.getYear();

    }
}

bool Comedy::operator<(const Movie &toCompare) {

    if(getTitle() != toCompare.getTitle()){

        return getTitle() < toCompare.getTitle();

    }else{

        return getYear() < toCompare.getYear();

    }
}

void Comedy::toString(ostream& stream) const {

    stream << getTitle() << " " << getYear();

}

