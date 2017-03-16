/*---------- Class Description -----------
This class extends the movie class. This class is specifically the
implementation of a classic movie. It has all the elements of a movie, such as
the year of release, amount in stock, and the director of the movie.

In addition to these characteristics, a classic also has a major actor and the
month of release.
*/

#ifndef CLASSIC_H
#define CLASSIC_H

#include "movie.h"
#include <fstream>
#include <string>

using namespace std;

class Classic : public Movie {

public:

    //to string method, to print out this movie
    void toString(ostream& stream) const;

    //constructor, takes in the genre of the movie
    Classic(char genre);

    //sets the data of the movie, given an ifstream
	void setData(ifstream& infile);

    //comparison operators
    bool operator==(const Movie &toCompare);
    bool operator>(const Movie& toCompare);
    bool operator<(const Movie& toCompare);

    //assignment operator
    Movie& operator=(Movie& toCopy);
};

#endif
