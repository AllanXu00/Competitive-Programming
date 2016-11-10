#include <bits/stdc++.h>
using namespace std;

#define inf 1<<30
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _inp[4097], *_pinp=_inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

string a, b, ans, rem; ll n, tmp, cnt;  char t; 

string convert(int a){
	string ans;
	stringstream i;
	i << a;
	i >> ans;
	return ans;
}

void sub (string s1, string s2){
	int in = 0; tmp = 0; 
	while (s2.size()+in <= s1.size()){
		if (s2 > s1.substr(in, int(s2.size()))){
			if (in == 0 || s1[in-1] == '0'){
				if (tmp != 0 || in != 0) ans += convert(tmp);
				//cout << ans << '-' << endl;
				in++; tmp = 0; 
				continue; 
			}
			else {
				s1[in-1] -= 1; 
				s1[in] += 10; 
			}
		}
		for (int i = s2.size()-1; i >= 0;  i--){
			if (s1[i+in] < '0'){
				s1[i+in-1] -= 1; 
				s1[i+in] += 10; 
			}
			s1[i+in] -= s2[i] - '0';
			if (s1[i+in] < '0'){
				s1[i+in-1] -= 1; 
				s1[i+in] += 10; 
			}
		}
		tmp++;
		//cout << s1  << ' ' << tmp << endl;
	}
	ans += tmp; 
	s1.erase(0, min(s1.find_first_not_of('0'), s1.size()-1));
	rem = s1;
}

int main() {
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a >> b; ans = ""; 
		if (b == "0") cout << a << endl << 0 << endl << endl;
		else{ 
        		sub (a, b);
        		if (ans.size() == 1) cout << 0 << endl << rem << endl << endl;
        		else cout << ans << endl << rem << endl << endl;
		}
	}
	return 0;
}
