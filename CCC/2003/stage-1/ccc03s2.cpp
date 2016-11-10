#include<iostream>
#include<string>
#include<sstream>
#include<ctype.h>

int numTests;

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::stringstream;

typedef string syllable;

bool isVowel(char p) {
	return
		p == 'a' || p == 'e' || p == 'i' || p == 'o' || p == 'u' || p == ' ' ||
		p == 'A' || p == 'E' || p == 'I' || p == 'O' || p == 'U';
}

void cutUpString(string &para) {
	int size = para.size();
	int diff = 0;
	bool usingDiff = false;
	for (int a = size - 1; a >-1; a--) {
		if (isVowel(para[a])) {

			usingDiff = true;
			diff = a;
			break;
		}
	}
	if (usingDiff) {
		para.erase(0, diff);
	}
}

void testCase() {
	string scores[4];
	for (int a = 0; a<4; a++) {
		string input;
		getline(cin, input);
		//stringstream SS(input);
		//while (SS >> input);
		cutUpString(input);
		for (int a = 0; a < input.size(); a++) {
			input[a] = toupper(input[a]);
		}
		
		scores[a] = input;
	}
	if (scores[0] == scores[1] && scores[1] == scores[2] && scores[2] == scores[3]) {
		cout << "perfect\n";
	} else if (scores[0] == scores[3] && scores[1] == scores[2] && scores[0] != scores[1]) {
		cout << "shell\n";
	} else if (scores[0] == scores[1] && scores[2] == scores[3] && scores[1] != scores[2]) {
		cout << "even\n";
	} else if (scores[0] == scores[2] && scores[1] == scores[3] && scores[2] != scores[3]) {
		cout << "cross\n";
	} else {
		cout << "free\n";
	}
}

int main() {
	string in;
	getline(cin, in);
	stringstream SS(in);
	SS >> numTests;
	for (int a = 0; a<numTests; a++) {
		testCase();
	}
}
