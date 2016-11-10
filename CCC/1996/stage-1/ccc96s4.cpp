#include <bits/stdc++.h>
using namespace std;

#define inf 1<<30
#define ll long long
#define mp make_pair
#define pb push_back
char _inp[4097], *_pinp=_inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

std::string roman(int x){
	if (x > 1000) return "CONCORDIA CUM VERITATE";
	static std::string H[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
	static std::string T[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
	static std::string O[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
	return std::string (x/1000, 'M') + H[(x%=1000)/100] + T[x/10%10] + O[x%10];
}

int normal (string s){
	int t, t2=1000000, ans = 0;
	for (int i = 0; i < s.length(); i++){
		if (s[i] == 'I') t = 1;
		if (s[i] == 'V') t = 5;
		if (s[i] == 'X') t = 10;
		if (s[i] == 'L') t = 50;
		if (s[i] == 'C') t = 100;
		if (s[i] == 'D') t = 500;
		if (s[i] == 'M') t = 1000;
		if (t > t2) ans += t - 2*t2;
		else ans += t;
		t2 = t;
	}
	return ans;
}

string a, b, c; 
int n, p;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        cin >> a; p = a.find("+");
        b = a.substr(0, p); c = a.substr(p+1, a.length()-p-2);
       // cout << normal(b)  << " " << normal(c) << endl;
        cout << a << roman(normal(b) + normal(c)) << endl;
    }
	return 0;
}
