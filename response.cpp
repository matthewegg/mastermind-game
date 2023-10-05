/*
    Matthew Egg and Charlie Daigle
    Project 1
    Implementation file for the Response class
*/

#include <iostream>
#include "response.h"

using namespace std;

// Class functions
void Response::setCorrect(int corr) {
    this->correct = corr;
}

void Response::setWrongSpots(int wrong) {
    this->wrongPlace = wrong;
}

const int Response::getCorrect() {
    return this->correct;
}

const int Response::getWrongSpots() {
    return this->wrongPlace;
}

bool operator ==(Response &resp1, Response &resp2) {
    return (resp1.getCorrect() == resp2.getCorrect() && resp1.getWrongSpots() == resp2.getWrongSpots());
}

ostream& operator<<(ostream& out, Response &resp) {
    cout << resp.getCorrect() << " correct" << endl;
	cout << resp.getWrongSpots() << " right digits in incorrect spots" << endl;
    return out;
}