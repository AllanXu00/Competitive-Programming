#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//variables
	int goal, club, number_clubs;
	long position[5380];
	position[0]=0;
	for(int i = 1; i < 5281; i++)
	{
		position[i]=10000000;
	}
	vector <int> clubs;
	cin >> goal >> number_clubs;
	for(int i = 0; i < number_clubs; i++)
	{
		cin >> club;
		clubs.push_back(club);
	}
	for(int i = 0; i <= 5280; i++)
	{
		for(int j= 0; j < number_clubs; j++)
		{
			position[i+clubs[j]] = min(position[i+clubs[j]],position[i]+1);
		}
	}
	if(position[goal]==10000000)
	{
		cout << "Roberta acknowledges defeat.";
	}
	else
	{
	cout << "Roberta wins in "<< position[goal]<<" strokes.";
	}
	
	return 0;
}
