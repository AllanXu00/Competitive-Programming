#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;

int numNodes;



int main() {
	vector<pair<std::string, char> > route;
	while (1) {
		char tempC;
		std::string tempS;
		cin >> tempC >> tempS;
		route.push_back(pair<std::string, char>(tempS, tempC));
		if (tempS == "SCHOOL")
			break;
	}
	int size = route.size();
	for (int a = 0; a<size; a++) {
		cout << "Turn ";
		if (route[size - a - 1].second == 'L') {
			cout << "RIGHT";
		} else {
			cout << "LEFT";
		}
		if (a == size - 1) {
			cout << " into your HOME.\n";
		} else {
			cout << " onto " << route[size - a - 2].first << " street.\n";
		}
	}

}; 
