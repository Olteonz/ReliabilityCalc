#include "main.h"
#include "Calculator.h"
#include "Data.h"


#include <iostream>
#include "Problem1.h"
#include "Problem2.h"
#include "Problem3.h"
#include "Problem4.h"
#include "Problem5.h"

using namespace std;

int main()
{	
	bool working = true;

	 do {
		Problem1 problem1;
		Problem2 problem2;
		Problem3 problem3;
		Problem4 problem4;
		Problem5 problem5;

		cout << "\033[1;31m Choose a problem from 1-5 (0 to exit):\033[0m\n";
		int x = 0;
		cin >> x;

		switch (x) {

			case 0: working = false; break;
			
			case 1: problem1.solve(); break;
	
			case 2: problem2.solve(); break;
			
			case 3: problem3.solve(); break;

			case 4: problem4.solve(); break;
			
			case 5: problem5.solve(); break;
		}
	}while (working == true);

	/*
	Problem1 problem1;
	problem1.solve();
	Problem2 problem2;
	problem2.solve();
	Problem3 problem3;
	problem3.solve();
	char k;
	std::cin >> k;
	
	Problem4 problem4;
	problem4.solve();
	
	Problem5 problem5;
	problem5.solve();
	*/
}
