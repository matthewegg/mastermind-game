/*
	Matthew Egg and Charlie Daigle
	Project 1
	Header file for the Mastermind class
*/

#include "code.h"
#include "response.h"
#ifndef mastermind_H
#define mastermind_H

using namespace std;

class Mastermind {

    public:
        // Constructors
        Mastermind();
        Mastermind(int n1, int m1);

        //Member functions
        Code humanGuess();
        Response getResponse(Code &guess);
        bool isSolved(Response &resp);
        void playGame();

    private:
        Code code;
        int n;
        int m;

};

#endif