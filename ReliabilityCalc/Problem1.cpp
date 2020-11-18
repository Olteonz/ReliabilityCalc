#include "Problem1.h"
#include "Calculator.h"
#include "Data.h"
#include <iostream>

/*The equipment in a packaging plant has a MTBF of 1000 hours. What is the probability that
the equipment will operate for a period of 500 hours without failure ?*/
//Aleksander Mielczarek

void Problem1::solve() {

	Data problem1;
	problem1.MTBF = 1000;

	std::cout << "The equipment in a packaging plant has a MTBF of 1000 hours. What is the probability that the equipment will operate for a period of 500 hours without failure ? \n";
	std::cout << "The probability is: " << probabilityOfWorkingWithoutFailureInTime(problem1, 500) * 100 << "%";
};
