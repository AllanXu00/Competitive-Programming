#include <iostream>
#include <stack>
using namespace std;

int main() {
	int a, b, min, max; 
	bool works;
	cin >> a; 
	for (int i = 0; i < a; i++)
	{
		stack <int> c;
		min = 0; 
		works = true;
		cin >> b; 
		int ar [b];
		for (int i = b-1; i >= 0; i--)
		{
			cin >> ar[i];
		}
		for (int i = 0; i < b; i++)
		{
			if (!c.empty())
			{
				while (c.top()==min+1)
				{
					c.pop();
					min++;
				}
			}
			max = 1000000;
			if (!c.empty())
			{
			max = c.top();
			}
			if (ar[i]!=min+1&&ar[i]>max)
			{
				works = false;
				break;
			}
			else if (ar[i]!=min+1&&ar[i]<max)
			{
				c.push(ar[i]);
			}
			else if (ar[i]==min+1)
			{
				min++;
			}
			
			
		}
		while (!c.empty())
		{
			c.pop();
		}
		if (works)
		{
			cout << "Y" << endl;
		}
		else
		{
			cout << "N" << endl;
		}
	}
	return 0;
}
 
