//
// Created by Kevin on 3/3/2017.
//

#include <iostream>
#include <iomanip>
#include "drama.h"
#include "../globals.h"

Drama::Drama(char genre){

    setGenre(genre);
}

void Drama::setData(ifstream &infile) {

    Movie::setData(infile);

    string store;

    //read in year
    getline(infile, store);
    global_functions::trimString(store);
    setYear(stoi(store));
}

bool Drama::operator==(const Movie &toCompare){

    return (getDirector() == toCompare.getDirector() &&
            getTitle() == toCompare.getTitle());
}

bool Drama::operator>(const Movie &toCompare) {

    if(getDirector() != toCompare.getDirector()){

        return getDirector() > toCompare.getDirector();

    }else{

        return getTitle() > toCompare.getTitle();

    }
}

bool Drama::operator<(const Movie &toCompare) {

    if(getDirector() != toCompare.getDirector()){

        return getDirector() < toCompare.getDirector();

    }else{

        return getTitle() < toCompare.getTitle();

    }
}

void Drama::toString(ostream& stream) const {

    stream << getDirector() << " " << getTitle();

}
