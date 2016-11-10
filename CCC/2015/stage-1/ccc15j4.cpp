#include <iostream>
using namespace std;
 
int main() {
	int a, time = 0, temp; 
	pair <bool, pair <int, int> > friends [101];
	for (int i = 0; i < 101; i++)
	{
		friends[i].first = false;
		friends[i].second.first = 0;
		friends[i].second.second=0;
	}
	cin >> a; 
	char b;
	for(int i = 0; i < a; i++)
	{
		cin >> b >> temp;
		if (b=='W')
		{
			time+=temp-2;
		}
		else if (b=='R')
		{
			friends [temp].first = true;
			friends [temp].second.first += time;
			//cout << time << endl;
		}
		else if (b=='S')
		{
			 friends [temp].second.second += time;
			 //cout << time << endl;
		}
 
		time++;
	}
	for (int i = 0; i < 101; i++)
	{
		if (friends[i].first==true)
		{
			cout << i << " ";
			if(friends[i].second.second - friends[i].second.first<=0)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << friends[i].second.second- friends[i].second.first << endl;
			}
 
		}
 
 
	}
	return 0;
}
