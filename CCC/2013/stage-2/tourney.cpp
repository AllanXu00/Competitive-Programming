#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

int a, b, x, y, z, dis, judge;
float s1;
map <int, int> winner;
char w;
int ar [1500000];
int tree[6000000];
int constS = 1 << 30;
int constB = 100000;
//cout
inline int merge(int a, int b) { return a > b ? a : b; }

void build(int n, int lo, int hi)
{
	if (lo==hi)
	{
		tree[n]=ar[hi];
		return;
	}
	build (2*n+1, lo, (lo+hi)/2);
	build (2*n+2, (lo+hi)/2+1, hi);
	tree[n]=merge (tree[2*n+1], tree[2*n+2]);
	
}

void update(int n, int lo, int hi)
{
	if (hi < x || lo > x) return;
	if (lo==hi)
	{
		tree[n] = y;
		return;
	}
	update(2*n + 1, lo, (lo + hi)/2);
  	update(2*n + 2, (lo + hi)/2 + 1, hi);
	tree[n] = merge(tree[2*n + 1], tree[2*n + 2]);
}

int query (int n , int lo, int hi)
{
	if (hi < x || lo > y) return constS;
	if (lo >= x && hi <= y) return tree[n];
	return merge (query (2*n+1, lo, (lo+hi)/2), query(2*n + 2, (lo + hi) / 2 + 1, hi));
}

void win(int n, int lo, int hi)
{
	if (hi < x || lo > x) return;
	if (tree[n]==y) dis++;
	//cout << tree[n] << endl;
	if (lo==hi)
	{
		return;
	}
	win(2*n + 1, lo, (lo + hi)/2);
  	win(2*n + 2, (lo + hi)/2 + 1, hi);
	
}



int main() {
	
	cin >> a >> b; 
	s1=2.0;
	judge = int (pow(s1, a)-1);
	for (int i = 0; i < judge+1; i++)
	{
		cin >> ar[i];
		winner[ar[i]]=i+1;
		//cout << ar[i] << endl;
		//cout << i << endl;
	}
	build (0, 0, judge);
	
	for (int i = 0; i < b; i++)
	{
		cin >> w; 
	
		if (w=='S')
		{
			cin >> x;
			x--;
			y=ar[x];
			//cout << y << endl;
			dis=0;
			win (0, 0, judge);
			cout << max (0, dis-1) << endl;
		}
		else if (w=='W')
		{
			x=0; 
			y=judge;
			cout << winner[tree[0]]<<endl;
		}
		else if (w=='R')
		{
			cin >> x >> y;
			winner[y]=x;
			x--;
			ar[x]=y;
			update(0, 0, judge);
			//cout << "I triee";
		}
	}
	
	return 0;
}
