#include "Problem4.h"
#include "Calculator.h"
#include "Data.h"
#include <iostream>

/*California Instruments, Inc., produces 3,000 computer chips per day. Three hundred are tested for a
period of 500 operating hours each. During the test, six failed: two after 50 hours, two at 100 hours,
one at 300 hours, and one at 400 hours.
Find FR(%) and FR(N).*/
//Jakub Kowalewski

void Problem4::solve() {

	Data problem1;
	problem1.MTBF = 1000;

	std::cout << "The equipment in a packaging plant has a MTBF of 1000 hours. What is the probability that the equipment will operate for a period of 500 hours without failure ? \n";
	std::cout << "The probability is: " << probabilityOfWorkingWithoutFailureInTime(problem1, 500) * 100 << "%";
};
