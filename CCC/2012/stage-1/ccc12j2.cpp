#include <iostream>
using namespace std;

int main() {
	int a[4]; 
	int check = 3; 
	bool ch = true;
	for(int i = 0; i < 4; i++)
	{
		cin >> a[i];
	}

	for(int i = 0; i < 3; i++)
	{
		if(a[i]!=a[i+1])
		{
			ch = false;
		}
		if (a[i]<a[i+1])
		{
			check++;
		}
		else if(a[i]>a[i+1])
		{
			check--;
		}
	}
	if (ch==true)
	{
		cout << "Fish At Constant Depth";
	}
	else if(check==6)
	{
		cout << "Fish Rising";
	}
	else if (check==0)
	{
		cout << "Fish Diving";
	}
	else
	{
		cout << "No Fish";
	}
	return 0;
}
