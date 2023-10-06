/*
    Matthew Egg and Charlie Daigle
    Project 1
    Header file for the Response class
*/

#include <iostream>
#ifndef response_H
#define response_H

using namespace std;

class Response 
{

    public:

        // Constructor
        Response() : correct(0), wrongPlace(0) {};
        Response(int correct, int wrongSpots) : correct(correct), wrongPlace(wrongSpots) {};

        // Class functions
        void setCorrect(int corr);
        void setWrongSpots(int wrong);
        const int getCorrect();
        const int getWrongSpots();
        bool operator ==(Response &resp);
        friend ostream & operator<<(ostream &out, Response &resp); 

    private:
        int correct;
        int wrongPlace;
};

#endif