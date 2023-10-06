/*
	Matthew Egg and Charlie Daigle
	Project 1
	Implementation file for the Code class
*/

#include <random>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <bits/stdc++.h>
#include "code.h"

using namespace std;

/** Randomizes the digits of a Code object
 * 
 * Assumptions: none
 * Limitations: none
 * 
 */
void Code::randomizeCode() {
	srand(time(NULL));

	for (int i=0; i<size; i++)
	{
		code[i] = rand() % maxRange;
	}
}

/** Overloads << to pretty-print code
 * 
 * Assumptions: none
 * Limitations: none
 */
ostream & operator<<(ostream &out, Code &c)
{
	cout << "{";

	for (int i=0; i < c.code.size(); i++)
	{
		cout << c.code[i];

		// Post-condition -- skip comma after last element
		if (i < c.code.size() - 1)
			cout << ", ";
	}

	cout << "}";

	return out;
}

/** Counts the number of correct guesses in correct locations.
 * 
 * Assumptions: none
 * Limitations: none
 */
const int Code::checkCorrect(Code &guess) 
{
	int total = 0;

	for (int i=0; i<size; i++)
	{
		if (code[i] == guess.code[i]) total++;
	}

	return total;
} 

/** Counts the number of correct guesses in INCORRECT locations.
 *  Does not count digits more than once.
 * 
 * Assumptions: none
 * Limitations: none
 * 
 */
const int Code::checkIncorrect(Code &guess)
{
    vector<int> alreadyCounted(0);
	
	// Compare each combination of items in the actual and guessed code, and if there are matching items in different locations, add the value to the list. Still uses the algorithm library to see if a value is in the list of already accounted for numbers.
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (this->code[i] == guess.code[j]) {
				if (i != j) {
					if (!(count(alreadyCounted.begin(), alreadyCounted.end(), this->code[i]))) {
						alreadyCounted.insert(alreadyCounted.begin(), this->code[i]);
					}
				}
			}
        }
    }

	return alreadyCounted.size();
}