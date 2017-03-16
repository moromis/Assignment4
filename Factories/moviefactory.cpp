//
// Created by Kevin on 3/10/2017.
//

#include <sstream>
#include <iostream>
#include "moviefactory.h"
#include "../Movies/comedy.h"
#include "../Movies/drama.h"
#include "../Movies/classic.h"
#include "../globals.h"


//------------------------------------------------------------------------------
/*
 * CREATEMOVIE
 *
 * Description:
 * Creates a Movie, based on the passed genre char. movie is set to the newly
 * instantiated Movie, based on the principle of polymorphism. A bool
 * representing the success of the instantiation is returned.
 *
 *
 * Preconditions: A movie needs to be created.
 *
 * Postconditions: A bool indicating the success of movie's instantiation has
 * been returned, and if the genre is a correct char (currently F, D, or C),
 * then movie has been bound to the correct type of movie
 */
bool MovieFactory::createMovie(ifstream& infile, char genre, Movie*& movie) {

    //switch based off of the char genre of the Movie
    switch(genre){
        case 'F': {

            //if we have a "funny" (F) Comedy, create a new Comedy and set
            // the data within that Movie
            movie = new Comedy(genre);
            movie->setData(infile);
            return true;

        }
        case 'D': {

            //if we have a Drama (D), create a new Drama and set
            // the data within that Movie
            movie = new Drama(genre);
            movie->setData(infile);
            return true;
        }
        case 'C': {

            //if we have a Classic (C), create a new Classic and set
            // the data within that Movie
            movie = new Classic(genre);
            movie->setData(infile);
            return true;
        }
        default: {

            //otherwise, grab the rest of the line and return false, to
            // indicate that the genre given is not a correct genre
            string store;
            getline(infile, store);
            return false;
        }
    }
}


//------------------------------------------------------------------------------
/*
 * CREATEPARTIALMOVIE
 *
 * Description:
 * Creates a Movie, based on the passed genre char. This class is used to
 * create partial movies from the commands file, and is called from the
 * transaction factory.
 *
 *
 * Preconditions: A movie needs to be created.
 *
 * Postconditions: If the genre is a correct char (currently F, D, or C),
 * then a movie has been created of the correct type and returned to the
 * calling function.
 */
Movie* MovieFactory::createPartialMovie(char genre, ifstream& infile){

    string store;
    Movie* movie = nullptr;

    switch(genre) {
        case 'D': {

            //if we have a Drama (D), create a new Drama and set
            // the data within that Movie
            movie = new Drama(genre);

            getline(infile, store, ',');
            global_functions::trimString(store);
            movie->setDirector(store);

            getline(infile, store, ',');
            global_functions::trimString(store);
            movie->setTitle(store);

            return movie;
        }
        case 'F': {

            //if we have a "funny" (F) Comedy, create a new Comedy and set
            // the data within that Movie
            movie = new Comedy(genre);

            getline(infile, store, ',');
            global_functions::trimString(store);
            movie->setTitle(store);

            infile >> store;
            movie->setYear(stoi(store));

            return movie;
        }
        case 'C': {

            //if we have a Classic (C), create a new Classic and set
            // the data within that Movie
            movie = new Classic(genre);

            infile >> store;
            global_functions::trimString(store);
            movie->setMonth(stoi(store));

            infile >> store;
            global_functions::trimString(store);
            movie->setYear(stoi(store));

            getline(infile, store);
            global_functions::trimString(store);
            movie->setMajorActor(store);

            return movie;
        }
        default: {

            //print an error, since the genre is not among the genres we
            // currently recognize
            stringstream ss;
            ss << "ERROR: '" << genre << "' is not a valid "
                    "genre" << endl;
            cout << ss.str();

            return movie;
        }
    }
}
