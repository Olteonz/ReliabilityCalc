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
using namespace std;

void Problem5::solve() {

	float cost, expectedNum=0, tempBreak = 0, tempFreq = 0;

	cout << "Cost per breakdown in $: ";
	cin >> cost;

	cout << "Number of breakdowns with their  daily frequency? (to end write 0)" << endl;
	do {
		cout << "Number of breakdowns: ";
		cin >> tempBreak;
		if (tempBreak == 0) {
			break;
		}
		cout << "Daily Frequency: ";
		cin >> tempFreq;
		expectedNum += (tempBreak*(tempFreq/10));
	} while (true);
	cout << "Expected number of breakdowns: " << expectedNum << " breakdowns/day"<<endl;
	cout << "Expected breakdown cost: " << expectedNum*cost << "$/day" << endl;
};
