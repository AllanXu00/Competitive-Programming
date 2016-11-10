#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int lim, h, temp; 
	cin >> h >> lim; 
	double j;
	for(int i = 1; i <= lim; i++)
	{
		j = int(i);
		temp = -6*pow(j, 4) + h*pow(j,3)+2*pow(j, 2)+j;
		if (temp <= 0)
		{
			
			cout <<"The balloon first touches ground at hour:"<<endl<< i<<endl;
			return 0;
		}
	}
	cout << "The balloon does not touch ground in the given time." << endl;
	return 0;
}
