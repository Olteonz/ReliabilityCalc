#include "main.h"
#include "Calculator.h"
#include "Data.h"


#include <iostream>
#include "Problem1.h"
#include "Problem2.h"
#include "Problem3.h"


int main()
{
	Problem1 problem1;
	problem1.solve();
	Problem2 problem2;
	problem2.solve();
	Problem3 problem3;
	problem3.solve();
	char k;
	std::cin >> k;
}
