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

    void toString(ostream& stream) const;

    Drama(char genre);

	void setData(ifstream& infile);

    //comparison operators
	bool operator==(const Movie &toCompare);
	bool operator>(const Movie& toCompare);
	bool operator<(const Movie& toCompare);

};

#endif