#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int a, b, c, x, y, dis, s1, s2, ans, g1, g2, co=0;
pair <pair <int, int>, pair <int, int> > pa;
char grid[1000][1000];
int dist[1000][1000];
int best[1000][1000];
bool visit [1000][1000];
bool visit1 [1000][1000];
queue <pair <pair <int, int>, pair <int, int> > > qu;
queue <pair <pair <int, int>, pair <int, int> > > qu1;


int main() {
	cin >> a >> b;
	for (int i = 1; i <= a ; i++)
	{
	    for (int j = 1; j <= a; j++)
	    {
            scanf (" %c", &grid[i][j]);
            dist[i][j]=1<<30;
            best[i][j]=-1;
            visit1[i][j]=false;
            if (grid[i][j]=='H')
            {
                pa.first.first = i;
                pa.first.second = j;
                pa.second.first = 0;
                qu.push(pa);
                //dist[i][j]=0;
            }
            if (grid[i][j]=='M')
            {
            	s1=i;
            	s2=j;
            }
            if (grid[i][j]=='D')
            {
            	g1=i;
            	g2=j;
            }
	    }
	}
	while (!qu.empty())
	{
	co++;
        x = qu.front().first.first;
        y = qu.front().first.second;
        dis = qu.front().second.first;
        qu.pop();
        visit1[x][y]=true;
        if (dist[x][y]>dis)dist[x][y]=dis;
        pa.first.first = x+1;
        pa.first.second = y;
        pa.second.first = dis+1;
        if (!visit1[x+1][y]&&grid[x+1][y]!='T'&&grid[x+1][y]!='D'&&x<a)qu.push(pa);
        visit1[x+1][y]=true;
        pa.first.first = x-1;
        pa.first.second = y;
        if (!visit1[x-1][y]&&grid[x-1][y]!='T'&&grid[x-1][y]!='D'&&x>1)qu.push(pa);
        visit1[x-1][y]=true;
        pa.first.first = x;
        pa.first.second = y+1;
        if (!visit1[x][y+1]&&grid[x][y+1]!='T'&&grid[x][y+1]!='D'&&y<a)qu.push(pa);
        visit1[x][y+1]=true;
        pa.first.first = x;
        pa.first.second = y-1;
        if (!visit1[x][y-1]&&grid[x][y-1]!='T'&&grid[x][y-1]!='D'&&y>1)qu.push(pa);
        visit1[x][y-1]=true;
	}
	pa.first.first = s1;
	pa.first.second = s2;
	pa.second.first = 0;
	pa.second.second = dist[s1][s2]-1;
	qu1.push(pa);
	while (!qu1.empty())
	{
	co++;
	x = qu1.front().first.first; 
	y = qu1.front().first.second;
        dis = qu1.front().second.first;
        ans = qu1.front().second.second;
        best[x][y]=max(best[x][y], ans);
        qu1.pop();
        if (co>20000000)
        {
            break; 
            //return 0;
        }
        pa.first.first = x+1;
        pa.first.second = y;
        pa.second.first = dis+1;
        pa.second.second = min (ans, dist[x+1][y]-(dis+b+1)/b);
        if (best[x+1][y]<pa.second.second&&pa.second.second>=0&&x<a&&grid[x+1][y]!='T')
        {
        	qu1.push(pa);
        	best[x+1][y]=pa.second.second;
        }
        pa.first.first = x-1;
        pa.first.second = y;
        pa.second.second = min (ans, dist[x-1][y]-(dis+b+1)/b);
        if (best[x-1][y]<pa.second.second&&pa.second.second>=0&&x>1&&grid[x-1][y]!='T')
        {
        	qu1.push(pa);
        	best[x-1][y]=pa.second.second;
        }
        pa.first.first = x;
        pa.first.second = y+1;
        pa.second.second = min (ans, dist[x][y+1]-(dis+b+1)/b);
        if (best[x][y+1]<pa.second.second&&pa.second.second>=0&&y<a&&grid[x][y+1]!='T')
        {
        	qu1.push(pa);
        	best[x][y+1]=pa.second.second;
        }
        pa.first.first = x;
        pa.first.second = y-1;
        pa.second.second = min (ans, dist[x][y-1]-(dis+b+1)/b);
        if (best[x][y-1]<pa.second.second&&pa.second.second>=0&&y>1&&grid[x][y-1]!='T')
        {
        	qu1.push(pa);
        	best[x][y-1]=pa.second.second;
        }
	}
	cout << best[g1][g2] << endl;
	return 0;
}
