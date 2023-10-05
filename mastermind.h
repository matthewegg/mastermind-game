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
        Mastermind() : n(5), m(10) {
            code = Code(n, m);
            code.randomizeCode();
        }
        Mastermind(int n1, int m1) : n(n1), m(m1) {
            code = Code(n, m);
            code.randomizeCode();
        }

        //Member functions
        Code humanGuess();
        Response getResponse(Code &guess);
        bool isSolved(Response &resp);
        void playGame();

    private:
        int n;
        int m;
        Code code;

};

#endif