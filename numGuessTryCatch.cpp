// Copyright (c) 2022 Ioana Marinescu All rights reserved.
// Created By: Ioana Marinescu
//
// Date: Nov. 4, 2022
// random number guessing game with try catch


#include <iostream>
#include <random>

int main() {
    // variables
    std::string userNumString;
    int userNumInt, randNum;

    // generating random number
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(0, 9);
    randNum = idist(rgen);

    // user input
    std::cout << "Please enter a number from 0 to 9: ";
    std::cin >> userNumString;

    // exception handling
    try {
        userNumInt = stoi(userNumString);

        // if userNum out of range
        if (userNumInt < 0 || userNumInt > 9) {
            std::cout << "Please input a number between 0 and 9!" << std::endl;

        // if user guessed random number
        } else if (userNumInt == randNum) {
            std::cout << "Correct! " << randNum <<
            " is the right number!" << std::endl;

        // if user did not guess the right number
        } else {
            std::cout << "Incorrect! " << randNum
            << " is the right number!" << std::endl;
        }
    } catch (std::exception) {
        std::cout << userNumString <<
        " is not a number! Please enter a valid input." << std::endl;
    }
}
