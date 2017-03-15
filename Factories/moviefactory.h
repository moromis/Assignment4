//
// Created by Kevin on 3/10/2017.
//

#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include "../Movies/movie.h"

using namespace std;

class MovieFactory {

public:

    bool createMovie(ifstream& infile, char genre, Movie*& movie);

    Movie* createPartialMovie(char genre, ifstream& infile);

};


#endif
