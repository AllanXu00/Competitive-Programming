#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, x, y, tot=0, rom=1, an=0; 
int grid [164][164];
char t;
vector <int> ans;

void traverse (int x1, int y1)
{
	if (x1>0 && x1 <= x && y1 > 0 && y1 <= y && grid [x1][y1] == 0)
	{
		tot++;
		grid [x1][y1]=rom;
		traverse (x1+1, y1);
		traverse (x1-1, y1);
		traverse (x1, y1+1);
		traverse (x1, y1-1);
	}
}

int main() {
	
	cin >> a >> x >> y; 
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= y; j++)
		{
			cin >> t;
			if (t=='.')
			{
				grid [i][j] = 0;
			}
			else
			{
				grid [i][j]=-1;
			}
			//cout << grid[i][j];
		}
	//	cout << endl;
	}
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= y; j++)
		{
			if (grid [i][j]==0)
			{
				traverse (i, j);
				rom++;
				ans.push_back(tot);
				tot=0;
			}
			
		}
	}
	sort (ans.begin(), ans.end());
	for (int i = ans.size()-1; i >= 0 ; i--)
	{
		if (ans[i]<=a)
		{
			a-=ans[i];
			//cout << ans[i] << endl;
			an++;
		}
		else
		{
			break;
		}
	}
	if (an==1)
	{
		cout << an << " room, " << a << " square metre(s) left over" << endl;
	}
	else
	{
		cout << an << " rooms, " << a << " square metre(s) left over" << endl;
	}
	
	return 0;
}
