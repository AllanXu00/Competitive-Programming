#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	vector <char> b;
	int n;
	string a, bi;
	getline (cin,a);
	getline (cin, bi);
	int g = bi.length();
	for(int i = 0; i < g; i++)
	{
		int n = bi[i];
		if (n<=90&&n>=65)
		{
			 b.push_back(bi[i]);
		}
	}
	int t = a.length();
	int u = b.size();
	int c [t];
	int temp; 
	
	for(int i = 0; i < t; i++)
	{
		c[i] = int(a[i]);
	}
	for(int i = 0; i < u; i++)
	{
		temp = b[i];
		temp += c[i%t];
		temp -= 65;
		if(temp>90)
		{
			temp -= 26;
		}
		cout << char (temp);
	}

	return 0;
}
