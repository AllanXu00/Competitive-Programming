#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int a, b, c, dis, zero; 
char x, y;
string light="", z; 
pair <string, int> pa; 
queue <pair <string, int> > qu; 
vector <string> ans;
map <string, bool> visit;
bool used; 

int main() {
	cin >> a; 
	for (int i = 0; i < a; i++)
	{
		cin >> x;
		light+=x;
	}
	//cout << light << endl;
	
	
	//cout << light;
	pa.first = light; 
	pa.second = 0;
	qu.push(pa);
	while (!qu.empty())
	{
		c=0;
		zero=0;
		z=qu.front().first; 
		b=qu.front().second;
		if (b>6)
		{
		    cout << 9 << endl;
    		    return 0;
		}
		qu.pop();
		visit[z]=true;
		//cout << z << " " << b << endl;
		for (int i = 0; i < a; i++)
		{
			
			if (z[i]=='0') 
			{
				c=0;
			}
			else if (z[i]=='1') c++;
			if (c==4)
			{
				z[i]--;
				z[i-1]--;
				z[i-2]--;
				z[i-3]--;
				//z[i-4]--;
				//cout << "4" << " ";
			}
			else if (c>4)
			{
				z[i]--;
			}
			
		}
		//cout << z << endl;
		zero=0;
		visit[z]=true;
		//cout << zero << endl;
		
		for (int i = 0; i < a; i++)
		{
			//used = false;
			if (z[i]=='0')
			{
			    zero++;
				z[i]++;
				pa.first = z; 
				pa.second = b+1;
				if (!visit[z])
				{
					visit[z]=true;
				    qu.push(pa);
				}
				z[i]='0';
			}
		}
		if (zero==a)
		{
			cout << b << endl;
			return 0;
		}
	}
	return 0;
}
