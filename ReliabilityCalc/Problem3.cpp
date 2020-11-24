#include "Problem3.h"
#include "Calculator.h"
#include "Data.h"
#include <iostream>
#include <vector>
#include "ReliabilitySystem.h"
#include <cmath>

/*Example 1.1-1.3 Bayes Formula from QITT03 - Reliability Test Planning & Weibull Analysis.pdf */
//Aleksander Mielczarek
using namespace std;

/*float reliabilityOfSystem(RealiabilityNode starting) {
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
	std::cout << "\nReliability of system from problem 3 in ch17pp.doc is: " << reliabilityOfSystem(node1)*100<<"%";
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
	
	
};*/
class BayesFormula {
public:
	float GetConfidence(float reliability, int sample_size) {
		return 1 - pow(reliability, sample_size+1);
	}
	float GetReliability(float confidence, int sample_size) {
		return pow(1 - confidence, 1.0 / (sample_size + 1));
	}
	float GetSampleSize(float confidence, float reliability) {
		return log(1 - confidence) /log(reliability) - 1;
	}
};


void Problem3::solve() {
	BayesFormula formula;
	cout << "This calculator will calculate either the reliability, confidence or sample size given the other values using the Bayes Formula\n input which value to find: 1 - Confidence, 2 - Reliability, 3 - Sample Size, other keys - exit: ";
	int e;
	cin >> e;
	float confidence;
	float reliability;
	int sample_size;
	switch (e)
	{
	case 1:
		cout << "Please input the reliability: ";
		while (!(cin >> reliability)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.  Try again: ";
		}
		cout << "Please input the sample size: ";
		while (!(cin >> sample_size)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.  Try again: ";
		}
		cout << "The confidence is: " << formula.GetConfidence(reliability, sample_size) * 100 << "%\n";
		break;
	case 2:
		cout << "Please input the confidence: ";
		while (!(cin >> confidence)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.  Try again: ";
		}
		cout << "Please input the sample size: ";
		while (!(cin >> sample_size)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.  Try again: ";
		}
		cout << "The reliability is: " << formula.GetReliability(confidence, sample_size) * 100 << "%\n";
		break;
	case 3:
		cout << "Please input the confidence: ";
		while (!(cin >> confidence)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.  Try again: ";
		}
		cout << "Please input the reliability: ";
		while (!(cin >> reliability)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.  Try again: ";
		}
		cout << "The sample size is: " << formula.GetSampleSize(confidence, reliability) << "\n";
		break;
	default:
		break;
	}

}