#include "Problem2.h"
#include "Calculator.h"
#include "Data.h"
#include <iostream>
#include <vector>

/*TALCO manufactures microwave ovens. In order to develop warranty guidelines, TALCO
randomly tested 10 microwave ovens continuously to failure. The failure information of the
10 ovens is shown in the table. */
//Aleksander Mielczarek

using namespace std;

float MTTF(vector<float> failures) {
	float MTTF = 0;
	for (int i = 0; i < failures.size(); i++) {
		MTTF += failures[i];
	}
	return MTTF / failures.size();
}

void Problem2::solve() {
	//vector<float> failures{2300, 2150, 2800, 1890, 2790, 1890, 2450, 2630, 2100, 2120};
	//cout << "TALCO manufactures microwave ovens. In order to develop warranty guidelines, TALCO randomly tested 10 microwave ovens continuously to failure.The failure information of the 10 ovens is shown in the table.\n";
	//cout << "The MTTF of the microwaves is: " << MTTF(failures);
	vector<float> failures;
	cout << "This calculator will output the MTBF based on failure information of the equipment\nInput number of equipment: ";
	int e;
	while (!(cin >> e)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}
	int timeToFail = 0;
	for (int i = 0; i < e; i++) {
		cout << "Input the time to fail of device nr. " << i + 1 << ": ";
		while (!(cin >> timeToFail)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.  Try again: ";
		}
		failures.push_back((float)timeToFail);
	}
	cout << "The MTTF of the equipment is: " << MTTF(failures) <<"\n";
};

