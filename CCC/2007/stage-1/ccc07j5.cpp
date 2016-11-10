#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	int a, b, c, d; 
	
	vector <int> vec;
	cin >> a >> b >> c; 
	int dp [100+c];
	vec.push_back(0);
	vec.push_back(990);
	vec.push_back(1010);
	vec.push_back(1970);
	vec.push_back(2030);
	vec.push_back(2940);
	vec.push_back(3060);
	vec.push_back(3930);
	vec.push_back(4060);
	vec.push_back(4970);
	vec.push_back(5030);
	vec.push_back(5990);
	vec.push_back(6010);
	vec.push_back(7000);
	
	for (int i=0; i < c; i++)
	{
		cin >> d; 
		vec.push_back(d);
		
	}
	sort (vec.begin(), vec.end());
	memset (dp, 0, sizeof dp);
	dp[0]=1;
	for (int i = 0; i < vec.size(); i++)
	{
		int n =i;
		while (n<=vec.size()-1)
		{
			n++;
			if (n>=vec.size()) break;
			//cout << vec[n] << " " << vec [i] << endl;
			if (vec[n]-vec[i]<=b&&vec[n]-vec[i]>=a)
			{
				dp[n]+=dp[i];
			}
			
			
		}
		//cout << i << " " << dp[i] << endl;
	}
	cout << dp [13+c];
	return 0;
}
