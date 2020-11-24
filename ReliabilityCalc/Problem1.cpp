#include "Problem1.h"
#include "Calculator.h"
#include "Data.h"
#include<limits>
#include <iostream>

/*The equipment in a packaging plant has a MTBF of 1000 hours. What is the probability that
the equipment will operate for a period of 500 hours without failure ?*/
//Aleksander Mielczarek

using namespace std;

void Problem1::solve() {

	Data problem1;
	//problem1.MTBF = 1000;

	//cout << "The equipment in a packaging plant has a MTBF of 1000 hours. What is the probability that the equipment will operate for a period of 500 hours without failure ? \n";
	//cout << "The probability is: " << probabilityOfWorkingWithoutFailureInTime(problem1, 500) * 100 << "%";
	cout << "This calculator will output the probability of failure in x hours based on the equipments MTBF \nInput MTBF: ";
	while (!(cin >> problem1.MTBF)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}
	cout << "Input operating time in hours: ";
	int time;
	while (!(cin >> time)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}
	cout << "The probability of failure in " << time << " hours is: " << probabilityOfWorkingWithoutFailureInTime(problem1, time) * 100 << "%\n";
};
