#include <iostream>
using namespace std;

int main() {
	int t, s, h;
	cin >> t >> s >> h;
	for (int i = 0; i < t; i++)
	{
		for(int j = 0; j<2; j++)
		{
			cout << '*';
			for (int n = 0; n < s; n++)
			{
				cout << ' ';
			}
		}
		cout << '*' << endl;
	}
	int m = 3+2*s;
	for (int i = 0; i < m; i++)
	{
		cout << '*';
	}
	cout << endl;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < m/2; j++)
		{
			cout << ' ';
		}
		cout << '*';
		for (int j = 0; j < m/2; j++)
		{
			cout << ' ';
		}
		cout << endl;
	}
	return 0;
}
