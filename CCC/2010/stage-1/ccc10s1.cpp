#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int a, t1, t2, t3;
	string nm;
	cin >> a; 
	pair <int, string> b [a];
	for (int i = 0; i < a; i++)
	{
		cin >> b[i].second;
		cin >> t1 >> t2 >> t3;
		b[i].first = 2*t1+3*t2+t3;
	}
	sort(b, b+a);
	if (a==0)
	{
		return 0;
	}
	if (a==1)
	{
		cout << b[0].second << endl;
		return 0;
	}
	
	for(int i = a-1; i >= 1; i--)
	{
		if (b[i].first>b[i-1].first)
		{
			cout << b[i].second << endl;
			if (i == a-1)
			{
				for(int j = a-2; j>=1; j--)
				{
					if (b[j].first>b[j-1].first)
					{
						cout << b[j].second << endl;
						return 0;
					}
				}
			}
			else
			{
				cout << b[i+1].second << endl;
				return 0;
			}
			
		}
		else if (b[i].first==b[i-1].first)
		{
			cout << b[i-1].second << endl << b[i].second << endl;
			return 0;
		}
	}
	
	
	return 0;
}
