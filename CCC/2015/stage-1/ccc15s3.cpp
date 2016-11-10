#include <iostream>
#include <set>
using namespace std;

int gates, port, x, ans;
set <int> g;
set <int> :: iterator pos;

int main() {
	cin >> gates >> port;
	for (int i = 1; i <= gates; i++) g.insert(i);
	for (int i = 0; i < port; i++){
		cin >> x; 
		pos = g.upper_bound(x);
		if (pos==g.upper_bound(-1)){
			cout << i << endl; 
			return 0; 
		}
		else{
			g.erase(*(--g.upper_bound(x)));
		}
		
	}
	cout << port << endl;
	return 0;
}
