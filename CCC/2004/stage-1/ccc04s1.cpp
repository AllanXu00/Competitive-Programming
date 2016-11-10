#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int a, pos;
	bool fi;
	cin >> a; 
	pair <int, string> fix [a][3];
	for (int i = 0; i < a; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cin >> fix[i][j].second;
			fix[i][j].first = fix[i][j].second.length();
		}
		sort (fix[i], fix[i]+3);
	}
	for(int i = 0; i < a; i++)
	{
		fi = false;
		pos = fix[i][2].second.find(fix[i][1].second);
		if (pos==0||pos==fix[i][2].second.length()-fix[i][1].second.length())
		{
			fi = true;
		}
		pos = fix[i][2].second.find(fix[i][0].second);
		if (pos==0||pos==fix[i][2].second.length()-fix[i][0].second.length())
		{
			fi = true;
		}
		pos = fix[i][1].second.find(fix[i][0].second);
		if (pos==0||pos==fix[i][1].second.length()-fix[i][0].second.length())
		{
			fi = true;
		}
		
		if (fi==true)
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" <<endl;
		}
	}
	return 0;
}
