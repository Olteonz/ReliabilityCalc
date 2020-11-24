#include "Problem3.h"
#include "Calculator.h"
#include "Data.h"
#include <iostream>
#include <vector>
#include "ReliabilitySystem.h"

/*Problem 3 from ch17pp.doc - Find the reliability of this system:*/
//Aleksander Mielczarek
using namespace std;

float reliabilityOfSystem(RealiabilityNode starting) {
	RealiabilityNode current = starting;
	float R = 1;
	while (true) {
		if (current.branch) {
			R *= current.reliability + (current.branch->reliability * (1 - current.reliability));
			std::cout << "[" << current.reliability << "+" << current.branch->reliability << "(1-" << current.reliability << ")]";
		}
		else
			R *= current.reliability;
		if (current.next) {
			current.reliability = current.next->reliability;
			current.branch = current.next->branch;
			current.next = current.next->next;
		}
		else
			break;
	} 
	return R;
}


void Problem3::solve() {
	/*RealiabilityNode node1;
	RealiabilityNode node2;
	RealiabilityNode node3;
	RealiabilityNode node1b;
	RealiabilityNode node3b;

	node1.branch = &node1b;
	node1.next = &node2;
	node1.reliability = 0.95;

	node1b.reliability = 0.92;

	node2.next = &node3;
	node2.branch = NULL;
	node2.reliability = 0.98;

	node3.next = NULL;
	node3.branch = &node3b;
	node3.reliability = 0.90;

	node3b.reliability = 0.90;
	std::cout << "\nReliability of system from problem 3 in ch17pp.doc is: " << reliabilityOfSystem(node1)*100<<"%";*/
	vector<RealiabilityNode> nodes;
	cout << "This calculator will output the reliability of a given system\nInput the number of nodes: ";
	int numberOfNodes;
	while (!(cin >> numberOfNodes)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}
	double reliability;
	RealiabilityNode x;
	RealiabilityNode branch;
	bool doesFirstNodeBranch = false;
	bool doesSecondNodeBranch = false;
	for (int i = 0; i < numberOfNodes; i++) {
		if (i != 0)
			x.next = &(nodes.back());
		cout << "Input the reliability of node nr. " << i + 1 << ": ";
		while (!(cin >> reliability)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.  Try again: ";
		}
		x.reliability = reliability;

		cout << "Does node nr. " << i + 1 << " have a backup? y/n";
		char backup;
		cin >> backup;
		switch (backup) {
		case 'n':
			x.branch = NULL;
			break;
		case 'y':
			cout << "Input the reliability of node nr. " << i + 1 << " backup: ";
			while (!(cin >> reliability)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input.  Try again: ";
			}
			branch.reliability = reliability;
			nodes.push_back(branch);
			x.branch = &(nodes.back());
			if(i==0)
				doesFirstNodeBranch = true;
			if (i == doesFirstNodeBranch + 1)
				doesSecondNodeBranch = true;
			i++;
			break;
		}
		nodes.push_back(x);
	}
	nodes[doesFirstNodeBranch].next = &(nodes[doesSecondNodeBranch + doesFirstNodeBranch + 1]);

	cout << "\nReliability of system from problem 3 in ch17pp.doc is: " << reliabilityOfSystem(nodes[doesFirstNodeBranch]) * 100 << "%";
	
	
};

