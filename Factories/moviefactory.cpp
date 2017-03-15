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

bool MovieFactory::createMovie(ifstream& infile, char genre, Movie*& movie) {

    switch(genre){
        case 'F': {

            movie = new Comedy(genre);
            movie->setData(infile);
            return true;

        }
        case 'D': {

            movie = new Drama(genre);
            movie->setData(infile);
            return true;
        }
        case 'C': {

            movie = new Classic(genre);
            movie->setData(infile);
            return true;
        }
        default: {

            string store;
            getline(infile, store);
            return false;
        }
    }
}

Movie* MovieFactory::createPartialMovie(char genre, ifstream& infile){

    string store;
    Movie* movie = nullptr;

    switch(genre) {
        case 'D': {

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

            movie = new Comedy(genre);

            getline(infile, store, ',');
            global_functions::trimString(store);
            movie->setTitle(store);

            infile >> store;
            movie->setYear(stoi(store));

            return movie;
        }
        case 'C': {

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

            stringstream ss;
            ss << "ERROR: '" << genre << "' is not a valid "
                    "genre" << endl;
            cout << ss.str();

            return movie;
        }
    }
}
