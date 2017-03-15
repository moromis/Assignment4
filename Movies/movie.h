/*---------- Class Description -----------
This class represents a movie in the store. It has many characterstics,
including the year of the movie's release, the title of the movie, and the
amount of the movie in stock.

Child classes of the movie class may have more attributes. The movie class
simply has the core attributes of any given movie.
*/

#ifndef MOVIE_H
#define MOVIE_H

#include <fstream>

using namespace std;

class Movie {

protected:

    virtual void toString(ostream& stream) const = 0;

    friend ostream& operator<<(ostream& stream, const Movie& movie);

private:
    //year that the movie released
	int year;
	
	//title of the movie
	string title;
	
	//physical copies of the movie in stock
	int stock;
	
	//director of the movie
	string director;

    //the genre of the movie
    char genre;

    //a major actor in the movie
    string majorActor;

    //month of the movie's release
    int month;

public:

    virtual void setData(ifstream &infile);

    //getter for the release year
    int getYear() const;

    //setter for the release year
    void setYear(int year);
    
    //getter for the title of the movie
    string getTitle() const;

    //setter for the title of the movie
    void setTitle(string title);

    //getter for the stock of the movie
    int getStock() const;

    //setter for the stock of the movie
    void setStock(int stock);

    //getter for the director of the movie
    string getDirector() const;

    //setter for the director of the movie
    void setDirector(string director);

    void setGenre(char genre);

    char getGenre() const;

    //getter for the majorActor field
    string getMajorActor() const;

    //setter for the majorActor field
    void setMajorActor(string majorActor);

    //getter for the month field
    int getMonth() const;

    //setter for the month field
    void setMonth(int month);

    //assignment operator
    virtual Movie& operator=(Movie& toCopy);

    //comparison operators
    virtual bool operator==(const Movie& toCompare) = 0;
    virtual bool operator>(const Movie& toCompare) = 0;
    virtual bool operator<(const Movie& toCompare) = 0;
};

#endif
