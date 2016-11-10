#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int a, b, t; 
	cin >> a; 
	bool fit;
	vector <int> box[a];
	for (int i = 0; i < a; i++)
	{
		cin >> t; 
		box[i].push_back(t);
		cin >> t; 
		box[i].push_back(t);
		cin >> t; 
		box[i].push_back(t);
		t = box[i][0]*box[i][1]*box[i][2];
		box[i].push_back(t);
		reverse(box[i].begin(), box[i].end());
	}
	sort (box, box+a);
	for (int i = 0 ; i<a; i++)
	{
	sort (box[i].begin(), box[i].end());
	}
	cin >> b; 
	vector <int> good[b];
	for(int i = 0; i < b; i++)
	{
		cin >> t; 
		good[i].push_back(t);
		cin >> t; 
		good[i].push_back(t);
		cin >> t; 
		good[i].push_back(t);
		sort(good[i].begin(), good[i].end());
	}
	
	for(int i = 0; i < b; i++)
	{
		fit = false;
		for (int j = 0; j < a; j++)
		{
			if (good[i][0] <= box[j][0]&&good[i][1] <= box[j][1]&&good[i][2] <= box[j][2])
			{
				cout << box[j][3] << endl;
				fit = true;
				break;
			}
			
		}
		if (!fit)
			{
				cout << "Item does not fit." << endl;
			}
	}
	
	return 0;
}
