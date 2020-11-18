#include "Problem2.h"
#include "Calculator.h"
#include "Data.h"
#include <iostream>
#include <vector>

/*TALCO manufactures microwave ovens. In order to develop warranty guidelines, TALCO
randomly tested 10 microwave ovens continuously to failure. The failure information of the
10 ovens is shown in the table. */
//Aleksander Mielczarek

float MTTF(std::vector<float> failures) {
	float MTTF = 0;
	for (int i = 0; i < failures.size(); i++) {
		MTTF += failures[i];
	}
	return MTTF / failures.size();
}

void Problem2::solve() {
	std::vector<float> failures{2300, 2150, 2800, 1890, 2790, 1890, 2450, 2630, 2100, 2120};
	std::cout << "TALCO manufactures microwave ovens. In order to develop warranty guidelines, TALCO randomly tested 10 microwave ovens continuously to failure.The failure information of the 10 ovens is shown in the table.\n";
	std::cout << "The MTTF of the microwaves is: " << MTTF(failures);
};

