/*
    Matthew Egg and Charlie Daigle
    Project 1
    Main function used to run the Mastermind game
*/

#include <iostream>
#include <bits/stdc++.h>
#include "code.h"
#include "response.h"
#include "mastermind.h"

using namespace std;

int main() {
    int n;
    int m;
    cout << "How many digits would you like in your code?: " << endl;
    cin >> n;
    cout << "What is the range of digits you would like in your code?: " << endl;
    cin >> m;
    Mastermind game(n, m);
    game.playGame();
    return 0;
}