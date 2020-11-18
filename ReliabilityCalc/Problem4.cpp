#include "Problem4.h"
#include "Calculator.h"
#include "Data.h"
#include <iostream>

/*California Instruments, Inc., produces 3,000 computer chips per day. Three hundred are tested for a
period of 500 operating hours each. During the test, six failed: two after 50 hours, two at 100 hours,
one at 300 hours, and one at 400 hours.
Find FR(%) and FR(N).*/
//Jakub Kowalewski

using namespace std;
void Problem4::solve() {

	cout << "Tested each day:";
	int tested;
	cin >> tested;
	cout << "Operating time:";
	float operatingTime;
	cin >> operatingTime;
	int x = 0;
	int failures = 0, tempFail;
	float downtime, tempTime;
	cout << "How much failed after what time?";
	do {
		cout << "How much: ";
		cin >> tempFail;
		failures += tempFail;
		cout << endl << "After what time (hours): ";
		cin >> tempTime;
		downtime += ((500 - tempTime) * tempFail);

	} while (x == 1);

	float frPerNumber = calculateFrPerNumber(failures, tested);
	float frPerTime = calculateFrPerTime(failures, tested, operatingTime, downtime);

	cout << "Failures per number tested = " << frPerNumber << "%";
	cout << "Failures per operating time = " << frPerTime << " failures/hour";
	cout << "MTBF = " << 1/frPerTime << " hours";
};

float