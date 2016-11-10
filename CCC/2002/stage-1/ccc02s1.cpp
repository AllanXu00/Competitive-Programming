#include <iostream>
#include <algorithm>
using namespace std;
int ans=0, tot, cur, last, pink, green, red, orange, p, g, r, o, mi=1000000;
void dfs (int cur, int last, int p, int g, int r, int o)
{
	if (cur>tot)return;
	else if (cur==tot)
	{
		cout << "# of PINK is " << p << " # of GREEN is " << g << " # of RED is " << r << " # of ORANGE is " << o << endl;  
		ans++;
		mi = min(mi, p+g+r+o);
	}
	else if (last==1)
	{
		dfs(cur+pink, 1, p+1, g, r, o);
		dfs(cur+green, 2, p, g+1, r, o);
		dfs(cur+red, 3, p, g, r+1, o);
		dfs(cur+orange, 4, p, g, r, o+1);
	}
	else if (last==2)
	{
		dfs(cur+green, 2, p, g+1, r, o);
		dfs(cur+red, 3, p, g, r+1, o);
		dfs(cur+orange, 4, p, g, r, o+1);
	}
	else if (last==3)
	{
		dfs(cur+red, 3, p, g, r+1, o);
		dfs(cur+orange, 4, p, g, r, o+1);
	}
	else if (last==4)
	{
		dfs(cur+orange, 4, p, g, r, o+1);
	}
}
int main() {
	cin >> pink >> green >> red >> orange >> tot;
	dfs (pink, 1, 1, 0, 0, 0);
	dfs (green, 2, 0, 1, 0, 0);
	dfs (red, 3, 0, 0, 1, 0);
	dfs (orange, 4, 0, 0, 0, 1);
	cout << "Total combinations is " << ans << '.' << endl;
	cout << "Minimum number of tickets to print is " << mi << '.' << endl;
	return 0;
}
