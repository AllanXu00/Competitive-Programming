#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int a, b, c; 
	cin >> a; 
	vector <int> sum [a];
	vector <int> dif[a];
	for (int i = 0; i < a; i++)
	{
		cin >> b; 
		c = 0;
		for(int j =1; j < b; j++)
		{
			if(b%j==0)
			{
				sum[i].push_back(j+(b/j));
				dif[i].push_back(abs(j-(b/j)));
			}
		}
		for (int j = 0; j < sum[i].size(); j++)
		{
			for(int n = 0; n < dif[i].size(); n++)
			{
				if(sum[i][j]==dif[i][n])
				{
					c = 1;
				}
			}
		}
		if (c==1)
		{
			cout << b << " is nasty" << endl;
		}
		else
		{
			cout << b << " is not nasty" << endl;	
		}
		
	}
	return 0;
}
