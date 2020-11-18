#include "Problem5.h"
#include "Calculator.h"
#include "Data.h"
#include <iostream>

/*  Given the probabilities below, calculate the expected breakdown cost.
	Breakdowns - Daily frequency
	0-3
	1-2
	2-2
	3-3
	Assume a cost of $10 per breakdown

*/
//Jakub Kowalewski

void Problem5::solve() {

	Data problem1;
	problem1.MTBF = 1000;

	std::cout << "The equipment in a packaging plant has a MTBF of 1000 hours. What is the probability that the equipment will operate for a period of 500 hours without failure ? \n";
	std::cout << "The probability is: " << probabilityOfWorkingWithoutFailureInTime(problem1, 500) * 100 << "%";
};
