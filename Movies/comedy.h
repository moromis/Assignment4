/*---------- Class Description -----------
This class extends the movie class. This class is specifically the
implementation of a comedy. It has no additional features as compared to a
movie currently.
*/

#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"
#include <fstream>

using namespace std;

class Comedy : public Movie {

public:

    //to string method, to print out this movie
    void toString(ostream& stream) const;

    //constructor, takes in the genre of the movie
    Comedy(char genre);

    //sets the data of the movie, given an ifstream
    void setData(ifstream& infile);

    //comparison operators
    bool operator==(const Movie &toCompare);
    bool operator>(const Movie& toCompare);
    bool operator<(const Movie& toCompare);

};

#endif