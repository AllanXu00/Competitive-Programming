#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int a, diff, ans, b, c, ar[100];
vector <int> vec;
bool check;

int main() {

    while (true){
        cin >> a;
        b = 1<<30;
        ans = 1<<30;
        if (a==0) return 0;
        for (int i = 0; i < a; i++){
            cin >> ar[i];
            if (i!=0) vec.push_back(ar[i]-ar[i-1]);
        }
        for (int i = 1; i < vec.size(); i++){
        	check = false;
            if (vec[i]==vec[0]){
            	check = true;
                for (int j = i; j < vec.size(); j++){
                    if (vec[j-i]!=vec[j]) check = false;
                }
                if (check) ans = min(ans, i);
            }
            
        }
        if (ans==1<<30) ans = vec.size();
        cout << ans << endl;
        vec.clear();
    }
	return 0;
}
