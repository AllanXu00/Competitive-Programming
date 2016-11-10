#include <iostream>
using namespace std;

int main() {
	int d;
	cin >> d;
	char a[10];
	a[0]=' ';
	a[1]='*';
	a[2]='x';
	a[3]='*';
	a[4]=' ';
	a[5]='x';
	a[6]='x';
	a[7]='*';
	a[8]=' ';
	a[9]='*';
	for(int k = 0; k < d; k++)
	{
	for(int i = 1; i < 4; i++)
	{
		
		
		for(int j = 0; j < d; j++)
		{
			cout << a[i];
		}
		if(i%3==0)
		{
			cout << endl;
		}
	}
	}
		for(int k = 0; k < d; k++)
	{
	for(int i = 4; i < 7; i++)
	{
		
		
		for(int j = 0; j < d; j++)
		{
			cout << a[i];
		}
		if(i%3==0)
		{
			cout << endl;
		}
	}
	}
		for(int k = 0; k < d; k++)
	{
	for(int i = 7; i < 10; i++)
	{
		
		
		for(int j = 0; j < d; j++)
		{
			cout << a[i];
		}
		if(i%3==0)
		{
			cout << endl;
		}
	}
	}
	return 0;
}
