//
// Created by Kevin on 3/10/2017.
//

#ifndef GLOBALS_H
#define GLOBALS_H

#include <sstream>

using namespace std;

//array and hash sizes
const int CURRENTMOVIEGENRES = 3;
const int POSSIBLEMOVIEGENRES = 26;
const int MAXHASHSIZE = 100;


//spacing constants (for printing)

const string HEADERTITLE= "                 MOVIE TITLE";
const string HEADERSTOCK = "                                        STOCK";

const int HEADERLENGTH = 50;

const int INITIALLENGTH = 17;
const string INITIALSPACES = "                 ";
const int TITLELENGTH = 53;
const string TITLESPACES =
        "                                                 ";

const string HEADERSTRING =
"###################################################"
        "##################################################";


//naming and char identifiers
const char movieGenres[CURRENTMOVIEGENRES]{ 'F', 'D', 'C' };
const string movieGenreNames[CURRENTMOVIEGENRES]{ "COMEDIES", "DRAMAS",
                                                   "CLASSICS" };

class global_functions {

public:

    //solution found here: http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
    //and modified to cut \n and \r characters from the end of the string
    static void trimString(string &in) {
        stringstream ss;
        ss << in;

        string s;
        string out;

        while (ss >> s) {

            out += (s + ' ');
        }

        if(out[out.length() - 1] == '\n'){
            out = out.substr(0, out.length() - 2);
        }

        if(out[out.length() - 1] == '\r'){
            out = out.substr(0, out.length() - 2);
        }

        in = out.substr(0, out.length() - 1);
    }
};

#endif
