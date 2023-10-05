/*
	Matthew Egg and Charlie Daigle
	Project 1
	Header file for the Code class
*/

#include <random>
#include <iostream>
#include <ctime>
#include <algorithm>
#ifndef code_H
#define code_H

using namespace std;

class Code {

	public:
		/**
		 * Constructors
		 */ 
		Code() : size(5), maxRange(10) {
            for (int i=0; i<size; i++)
			{
				code.push_back(0);
			}
        }
		Code(int n, int m) : size(n), maxRange(m) {
			for (int i=0; i<size; i++)
			{
				code.push_back(0);
			}
		}
		Code(vector<int> manualInputCode) : code(manualInputCode) {
			size = manualInputCode.size();
			maxRange = *max_element(manualInputCode.begin(), manualInputCode.end());
		}

		/**
		 * Class Methods
		 */
		
		// Assign random numbers to each entry in the code.  
		void randomizeCode();

		// Return the number of correct digits in the right location.
		const int checkCorrect(Code &guess);

		// Return the number of correct digits in the incorrect location.
		const int checkIncorrect(Code &guess);

		// Pretty-print the code.
		friend ostream & operator<<(ostream &out, Code &c); 

	private:
		vector<int> code;
		int size;
		int maxRange;

};

#endif