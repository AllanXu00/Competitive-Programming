#include <iostream>
using namespace std;

int main() {
	int a; 
	cin >> a; 
	cout << a << " in Ottawa" << endl;
	a-=300;
	a=a%2400;
	if (a<0)
	{
		a+=2400;
	}
	cout << a << " in Victoria" << endl;
	a+=100;
	a=a%2400;
	if (a<0)
	{
		a+=2400;
	}
	cout << a <<" in Edmonton" << endl;
	a+=100;
	a=a%2400;
	if (a<0)
	{
		a+=2400;
	}
	cout << a <<" in Winnipeg" << endl;
	a+=100;
	a=a%2400;
	if (a<0)
	{
		a+=2400;
	}
	cout << a <<" in Toronto" << endl;
	a+=100;
	a=a%2400;
	if (a<0)
	{
		a+=2400;
	}
	cout << a <<" in Halifax" << endl;
	a+=30;
	if (a%100>=60)
	{
		a-=60;
		a+=100;
	}
	a=a%2400;
	if (a<0)
	{
		a+=2400;
	}
	
	cout << a <<" in St. John's" << endl;
	return 0;
}
