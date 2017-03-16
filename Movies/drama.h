/*---------- Class Description -----------
This class extends the movie class. This class is specifically the
implementation of a drama. It has no additional features as compared to a
movie currently.
*/

#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"
#include <fstream>
#include <iomanip>

using namespace std;

class Drama : public Movie {

public:

    //to string method, to print out this movie
    void toString(ostream& stream) const;

    //constructor, takes in the genre of the movie
    Drama(char genre);

    //sets the data of the movie, given an ifstream
	void setData(ifstream& infile);

    //comparison operators
	bool operator==(const Movie &toCompare);
	bool operator>(const Movie& toCompare);
	bool operator<(const Movie& toCompare);

};

#endif
