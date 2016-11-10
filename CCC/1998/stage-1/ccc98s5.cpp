#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c, x, y, z, mi=10000000;
	pair <pair <int, int>, int> pa;
	queue <pair <pair <int, int>, int> > qu; 
	bool trip;
	cin >> a; 
	for (int i = 0; i < a; i++)
	{
		mi = 10000000;
		trip = false;
		cin >> b; 
		int grid [b+100][b+100];
		bool visit [b][b];
		
		for (int j = 0; j < b+100; j++)
		{
			for (int n = 0; n < b+100; n++)
			{
				grid[j][n] = -1000000;
				
			}
		}
		
		for (int j = 1; j <= b; j++)
		{
			for (int n = 1; n <= b; n++)
			{
				cin >> grid[j][n];
				visit [j][n]=false;
			}
		}
		
		
		pa.first.first = 1;
		pa.first.second =1;
		pa.second = 0;
		qu.push(pa);
		c = grid[1][1];
		//cout << c << endl;
		while (!qu.empty())
		{
			x=qu.front().first.first;
			y=qu.front().first.second;
			z=qu.front().second;
			qu.pop();
			//cout << x << " " << y <<" " << z << " " << grid[x][y] <<  endl;
			if (x==b&&y==b)
			{
				mi = min (mi, z);
				trip = true;
			}
			
			else if (!visit [x][y])
			{
				if (abs (grid[x][y]-grid[x-1][y]) <= 2 && !visit [x-1][y])
				{
					pa.first.first = x-1;
					pa.first.second=y;
					pa.second = z;
					if (grid[x][y]>c||grid[x-1][y]>c)
					{
						pa.second++;
					}
					
					qu.push(pa);
				}
				if (abs (grid[x][y]-grid[x+1][y]) <= 2&& !visit [x+1][y])
				{
					pa.first.first = x+1;
					pa.first.second=y;
					pa.second = z;
					if (grid[x][y]>c||grid[x+1][y]>c)
					{
						pa.second++;
					}
					
					qu.push(pa);
				}
				if (abs (grid[x][y]-grid[x][y-1]) <= 2&& !visit [x][y-1])
				{
					pa.first.first = x;
					pa.first.second=y-1;
					pa.second = z;
					if (grid[x][y]>c||grid[x][y-1]>c)
					{
						pa.second++;
					}
					
					qu.push(pa);
				}
				if (abs (grid[x][y]-grid[x][y+1]) <= 2&& !visit [x][y+1])
				{
					pa.first.first = x;
					pa.first.second=y+1;
					pa.second = z;
					if (grid[x][y]>c||grid[x][y+1]>c)
					{
						pa.second++;
					}
					
					qu.push(pa);
				}
			}
			visit [x][y]=true;
		}
		
		while (!qu.empty())
		{
			qu.pop();
		}
		if (!trip)
		{
			cout << "CANNOT MAKE THE TRIP" << endl << endl;
		}
		else
		{
			cout << mi << endl << endl;
		}
		
	}
	return 0;
}
