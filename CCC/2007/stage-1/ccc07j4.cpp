#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string a, b;
	getline (cin, a);
	getline (cin, b);
	a.erase(std::remove(a.begin(),a.end(),' '),a.end());
	b.erase(std::remove(b.begin(),b.end(),' '),b.end());
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	if (a==b)
	{
		cout << "Is an anagram.";
	}
	else
	{
		cout << "Is not an anagram."; 
	}
	return 0;
}
