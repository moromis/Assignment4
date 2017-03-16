//
// Created by Kevin on 3/10/2017.
//

#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "../Movies/movie.h"

using namespace std;

class MovieFactory {

public:

    //creates a movie
    bool createMovie(ifstream& infile, char genre, Movie*& movie);

    //creates a partially filled movie, used by Transaction
    Movie* createPartialMovie(char genre, ifstream& infile);

};


#endif
