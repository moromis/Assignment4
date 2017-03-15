//
// Created by Kevin on 3/10/2017.
//

#include "movie.h"
#include "../globals.h"

#include <iostream>
#include <iomanip>


int Movie::getYear() const{

    return year;
}

void Movie::setYear(int year){

    this->year = year;
}

string Movie::getTitle() const{

    return title;
}

void Movie::setTitle(string title){

    this->title = title;
}

int Movie::getStock() const{

    return stock;
}

void Movie::setStock(int stock){

    this->stock = stock;
}

string Movie::getDirector() const{

    return director;
}

void Movie::setDirector(string director){

    this->director = director;
}

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

Movie& Movie::operator=(Movie& toCopy) {

    toCopy.setTitle(title);
    toCopy.setYear(year);
    toCopy.setDirector(director);
    toCopy.setGenre(genre);

    return toCopy;
}

void Movie::setGenre(char genre) {
    this->genre = genre;
}

//char Movie::getGenre() const {
//    return genre;
//}

string Movie::getMajorActor() const{

    return majorActor;
}

void Movie::setMajorActor(string majorActor) {

    this->majorActor = majorActor;
}

int Movie::getMonth() const{

    return month;
}

void Movie::setMonth(int month) {

    this->month = month;
}

ostream &operator<<(ostream &stream, const Movie &movie) {

    movie.toString(stream);
    return stream;

}
