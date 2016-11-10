#include <iostream>
#include <stack>
using namespace std;

int main() {
	int a, b, t=0; 
	cin >> a; 
	stack <int> c; 
	for (int i = 0; i < a; i++)
	{
		cin >> b; 
		if (b == 0)
		{
			c.pop();
		}
		else
		{
			c.push(b);
		}
	}
	int te = c.size();
	for (int i = 0; i < te; i++)
	{
		t += c.top();
		c.pop();
		
	}
	cout << t;
	return 0;
}
