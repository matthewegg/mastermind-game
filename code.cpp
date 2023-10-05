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
		// code for ".at()" found here: https://www.geeksforgeeks.org/vectorat-vectorswap-c-stl/
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
	/* There is a bug where in the case of a code like {0, 1, 1, 3, 0} where the guess is {0, 1, 1, 3, 1} and the number of incorrectly placed numbers is 2 instead of 1.
	Not sure what causes it.
	
	*/
	return alreadyCounted.size();
}

/* This is the main function that was used to test the code for part 1. The main function for part 2 is in its own file.
int main()
{
	int n, m;
	cout << "Enter the length of your code:" << endl;
	cin >> n;
	cout << "Enter the range of your code:" << endl;
	cin >> m;
	Code c(n, m);
	c.randomizeCode();
	cout << "Original Code:" << endl;
	cout << c << endl;
	int correct = 0;
	int incorrect = 0;
	int guesses = 0;

	while (guesses < 10 && correct != n) {
		string guess;
		cout << "Enter your guess:" << endl;
		if (guesses == 0)
			cin.ignore();
		getline(cin, guess);
		vector<int> guess_vec;
		int ind1 = 0;
		int ind2 = 1;

		while(ind2 <= guess.length()) {
			string num = guess.substr(ind1, ind2-ind1);
			try {
				int num_int = stoi(num); // convert string to integer
				if (num_int > m) {
					// catching inputs greater than the range
					throw invalid_argument("Invalid guess. Your guess must be in the range [0, " + to_string(m - 1) + "].");
				}
				guess_vec.push_back(num_int);
				//cout << num_int << endl;
				//cout << guess_vec.size() << endl;
			} 
			catch (invalid_argument) {
				// catch non-integer input from the user
				throw invalid_argument("Invalid guess. Only integer inputs allowed.");
			}
			ind1 = ind2+2;
            ind2 = ind1+1;
		}

		if (guess_vec.size() != n) {
			cout << guess_vec.size() << endl;
			throw invalid_argument("Invalid guess. Your guess must have " + to_string(n) + " numbers.");
		}

		Code c_guess(guess_vec);
		correct = c.checkCorrect(c_guess);
		if (correct == n) {
			cout << "Congratulations! You win!" << endl;
			return 0;
		}
		incorrect = c.checkIncorrect(c_guess);
		cout << correct << " correct" << endl;
		cout << incorrect << " right digits in incorrect spots" << endl;
		guesses++;
	}

	cout << "Out of guesses. You lose." << endl;
	return 0;
}
*/