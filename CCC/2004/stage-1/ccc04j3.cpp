#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b; 
	cin >> a >> b; 
	string c[a], d[b];
	for(int i = 0; i < a; i++)
	{
		cin >> c [i];
	}
	for(int i = 0; i < b; i++)
	{
		cin >> d[i];
	}
	for(int i = 0; i < a; i++)
	{
		for(int j = 0; j < b; j++)
		{
			cout << c[i] << " as " << d[j]<< endl;
		}
	}
	return 0;
}
