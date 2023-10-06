/*
	Matthew Egg and Charlie Daigle
	Project 1
	Main function for part A
*/

#include <random>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <stdexcept>
#include "code.h"

int main()
{
	Code c(5, 7);	// initializing the randomly generated code
	c.randomizeCode();	// randomizing the code
	cout << "Secret Code:" << endl;
	cout << c << endl;	// printing the code
	Code guess1({5, 0, 3, 2, 6});	// initializing first requested guess
	Code guess2({2, 1, 2, 2, 2});	// initializing second requested guess
	Code guess3({1, 3, 3, 4, 5});	// initializing third requested guess
	
	cout << "Guess 1: " << guess1 << endl;	// printing first results
	cout << "Correct: " << c.checkCorrect(guess1) << endl;	// printing first guess correct number
	cout << "Incorrect Placement: " << c.checkIncorrect(guess1) << endl;	// printing first guess incorrect number
	cout << "Guess 2: " << guess2 << endl;	// printing second results
	cout << "Correct: " << c.checkCorrect(guess2) << endl;	// printing second guess correct number
	cout << "Incorrect Placement: " << c.checkIncorrect(guess2) << endl;	// printing second guess incorrect number
	cout << "Guess 3: " << guess3 << endl;	// printing third results
	cout << "Correct: " << c.checkCorrect(guess3) << endl;	// printing third guess correct number
	cout << "Incorrect Placement: " << c.checkIncorrect(guess3) << endl;	// printing third guess incorrect number

	return 0;
}