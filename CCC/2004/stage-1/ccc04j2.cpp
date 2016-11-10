#include <iostream>
using namespace std;

int main() {
	int a, b, c; 
	cin >> a >> b; 
	
	for (int i = 0; i < b; i++)
	{
	c = a + i * 60;
	if (c <= b)
	{
	cout << "All positions change in year "<< c << endl; 
	}
	else if (c > b)
	{
	break;
	}
	}
	return 0;
}
