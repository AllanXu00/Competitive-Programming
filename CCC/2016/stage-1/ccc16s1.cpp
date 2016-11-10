#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string a, b;
int c, pos, c2, c3, used;

int main() {
	cin >> a >> b;
	sort (a.begin(), a.end());
	sort (b.begin(), b.end());
	for (int i = 0; i , b.length(); i++){
        if (b[i]=='*') c++;
        if (b[i]!='*'){
            pos = i;
            break;
        }
	}
	for (int i = pos; i < b.length(); i++){
        for (int j = used; j < a.length(); j++){
            used++;
            if (b[i]==a[j]){
                c2++;
                break;
            }
        }
	}
	if (c+c2 >= a.length()) cout << "A" << endl;
	else cout << "N" << endl;
	return 0;
}
