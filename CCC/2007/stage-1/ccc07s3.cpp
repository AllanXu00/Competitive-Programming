#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main() {
	int a, i1, i2, x, y; 
	int graph[100000];
	bool visit [100000];
	bool cy, fr;
	pair <int, int> camel;
	queue <pair <int, int> > qu;
	cin >> a;
	for(int i = 0; i < a; i++)
	{
		cin >> i1; 
		cin >> graph[i1];
	}
	while (true)
	{
		cin >> i1 >> i2; 
		if(i1==0&&i2==0)
		{
			break;
		}
		x=i1;
		y=-1;
		fr = false;
		memset (visit, false, sizeof visit);
		while (!visit[x]&&x!=y)
		{
			visit [x] = true;
			x = graph [x];
			y++;
			if (x==i2)
			{
				fr = true;
				break;
			}
			
			
		}
		if (fr==true)
		{
			cout << "Yes " << y << endl;
		}
		else
		{
			cout << "No" << endl;
		}
		
	}
	return 0;
}
