#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int score [5];
bool visit [5][5];
int a, b, c, d, s1, s2, fav, ans;
bool check;
void dfs (int x, int y)
{
	check = true;
	if (x==4)
	{
		for (int i = 1; i < 5; i++)
		{
			if (i!=fav&&score[i]>=score[fav])
			{
				check=false;
			}
		}
		if (check)
		{
			ans++;
		}
		return;
	}
	//cout << x << " " << y << endl;
	if (x>4) return;
	else if (y>4)
	{
		//cout << "change y" << endl;
		x++;
		y=x+1;
		dfs (x, y);
		return;
	}
	else if (visit[x][y])
	{
		dfs (x, y+1);
		return;
	}
	
	
	else
	{
		visit [x][y]=true; 
		score[x]+=3;
		dfs (x, y+1);
		score[x]-=3;
		score[x]+=1;
		score[y]+=1;
		dfs (x, y+1);
		score[x]-=1;
		score[y]-=1;
		score[y]+=3;
		dfs (x, y+1);
		score[y]-=3;
		visit [x][y]=false; 
	}
}

int main() {
	cin >> fav >> b; 
	memset (score, 0, sizeof score);
	memset (visit, false, sizeof visit);
	for (int i = 0; i < b; i++)
	{
		cin >> c >> d >> s1 >> s2; 
		visit [c][d]=true; 
		visit [d][c]=true;
		if(s1>s2)
		{
			score[c]+=3;
		}
		else if (s1==s2)
		{
			score[c]++;
			score[d]++;
		}
		else
		{
			score[d]+=3;
		}
		
	}
	dfs (1, 2);
	cout << ans << endl;
	return 0;
}
