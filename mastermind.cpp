/*
	Matthew Egg and Charlie Daigle
	Project 1
	Implementation file for the Mastermind class
*/

#include <iostream>
#include <bits/stdc++.h>
#include "code.h"
#include "response.h"
#include "mastermind.h"

using namespace std;

/*
Mastermind::Mastermind() {
    n = 5;
    m = 10;
	code = Code(n, m);
	code.randomizeCode();
}

Mastermind::Mastermind(int n1, int m1) {
    n = n1;
    m = m1;
	code = Code(n, m);
	code.randomizeCode();
}
*/

Code Mastermind::humanGuess() {
    string guess;
    cout << "Enter your guess:" << endl;
	getline(cin, guess);
	guess.erase(remove(guess.begin(), guess.end(), ','), guess.end());
	vector<int> guess_vec;
    int ind1 = 0;
	int ind2 = 1;

    while(ind2 <= guess.length()) {
		string num = guess.substr(ind1, ind2-ind1);
		//cout << num << endl;
		//cout << "Index 1: " << ind1 << endl;
		//cout << "Index 2: " << ind2 << endl;
		if (num == " ") {
			ind1++;
        	ind2++;
        	continue; // skip empty strings
    	}

		for (char c : num) {
			if (!isdigit(c)) {
				throw invalid_argument("Invalid guess. Only integer inputs allowed.");
			}
    	}

		if (stoi(num) > m) {
			throw invalid_argument("Invalid guess. Your guess must be in the range [0, " + to_string(m - 1) + "].");
		}

		guess_vec.push_back(stoi(num));
		ind1 = ind2+1;
        ind2 = ind1+1;
	}

	if (guess_vec.size() != n) {
		cout << guess_vec.size() << endl;
		throw invalid_argument("Invalid guess. Your guess must have " + to_string(n) + " numbers.");
	}

	return Code(guess_vec);
}

Response Mastermind::getResponse(Code &guess) {
	int correct = 0;
	int incorrect = 0;
    correct = guess.checkCorrect(guess);
	incorrect = guess.checkIncorrect(guess);
	Response resp(correct, incorrect);
	return resp;
}

bool Mastermind::isSolved(Response &resp) {
    return (resp.getCorrect() == n && resp.getWrongSpots() == 0);
}

void Mastermind::playGame() {
	cout << "Code: " << this->code << endl;
	int guesses = 0;
	while (guesses < 10) {
		if (guesses == 0)
			cin.ignore();
		Code guess = this->humanGuess();
		Response resp = this->getResponse(guess);
		cout << resp << endl;
		if (this->isSolved(resp)) {
			cout << "You win!" << endl;
			break;
		}
		guesses++;
	}
	if (guesses == 10) {
		cout << "You lose!" << endl;
	}
}