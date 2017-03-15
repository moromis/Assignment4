//
// Created by Kevin on 3/3/2017.
//

#include "transaction.h"

int Transaction::getCustomerID() const {
    return customerID;
}

void Transaction::setCustomerID(int userID) {
    this->customerID = userID;
}

char Transaction::getTransactionType() const{
    return transactionType;
}

void Transaction::setTransactionType(char transactionType) {
    this->transactionType = transactionType;
}

char Transaction::getFormat() const{
    return format;
}

void Transaction::setFormat(char format) {
    this->format = format;
}

char Transaction::getGenre() const{
    return genre;
}

void Transaction::setGenre(char genre) {
    this->genre = genre;
}

int Transaction::getYear() const{
    return year;
}

void Transaction::setYear(int year) {
    this->year = year;
}

string Transaction::getActor() const{
    return actor;
}

void Transaction::setActor(string actor) {
    this->actor = actor;
}

Movie *Transaction::getMovie() const {
    return movie;
}

void Transaction::setMovie(Movie *movie) {
    this->movie = movie;
}
