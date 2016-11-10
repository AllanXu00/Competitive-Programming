#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, count=0; 
	cin >> a; 
	pair <string, string> d[a];
	for (int i = 0; i < a; i++)
	{
		cin >> d[i].first;
	}
	for (int i = 0; i < a; i++)
	{
		cin >> d[i].second;
	}
	for (int i = 0; i < a; i++)
	{
		if(d[i].first==d[i].second)
		{
			count++;
		}
		for(int j = 0; j < a; j++)
		{
			if(d[i].first==d[j].second && d[i].second!= d[j].first)
			{
				count++;
			}
		}
		
	}
	if(count >= 1)
	{
		cout << "bad";
	}
	else
	{
		cout << "good";
	}
	return 0;
}
