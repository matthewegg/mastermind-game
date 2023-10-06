/*
    Matthew Egg and Charlie Daigle
    Project 1
    Implementation file for the Response class
*/

#include <iostream>
#include "response.h"

using namespace std;

/** int -> void
 * 
 * Sets the amount of currently correct guesses.
 * 
 * Assumptions: none
 * Limitations: none
 **/

void Response::setCorrect(int corr) 
{
    this->correct = corr;
}


/** int -> void
 * 
 * Sets the amount of right digits in wrong spots.
 * 
 * Assumptions: none
 * Limitations: none
 **/
void Response::setWrongSpots(int wrong) 
{
    this->wrongPlace = wrong;
}

/** void -> const int
 * 
 * Gets the amount of currently correct guesses.
 * 
 * Assumptions: none
 * Limitations: none
 **/
const int Response::getCorrect() 
{
    return this->correct;
}

/** void -> const int
 * 
 * Gets the amount of currently right digits in wrong spots.
 * 
 * Assumptions: none
 * Limitations: none
 **/
const int Response::getWrongSpots() 
{
    return this->wrongPlace;
}

/** usage: Response == Response
 * 
 * Checks if two responses are equal.
 * 
 * Assumptions: none
 * Limitations: none
 **/
bool operator ==(Response &resp1, Response &resp2) 
{
    return (resp1.getCorrect() == resp2.getCorrect() && resp1.getWrongSpots() == resp2.getWrongSpots());
}

/** usage: cout << Response
 * 
 * Outputs the response parameters to provide hints to the player.
 * 
 * Assumptions: none
 * Limitations: none
 **/
ostream& operator<<(ostream& out, Response &resp) 
{
    cout << resp.getCorrect() << " correct" << endl;
	cout << resp.getWrongSpots() << " right digits in incorrect spots" << endl;
    return out;
}