#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f
#define mp make_pair
#define pb push_back
char _inp[4097], *_pinp=_inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

long long n, ar[6];
bool check;
priority_queue <pair <pair <int, int>, pair <pair <int, int>, pair <int, int> > > > q;

int main() {
	scan(n);
    for (int i = 0; i < n; i++){
    	for (int j = 0; j < 6; j++) scan(ar[j]); 
    	sort (ar, ar+6);
    	q.push(mp(mp(ar[0], ar[1]), mp(mp(ar[2], ar[3]), mp(ar[4], ar[5]))));
    }
    while (!q.empty()){
    	ar[0] = q.top().first.first;
    	ar[1] = q.top().first.second;
    	ar[2] = q.top().second.first.first;
    	ar[3] = q.top().second.first.second;
    	ar[4] = q.top().second.second.first;
    	ar[5] = q.top().second.second.second;
    	q.pop();
    	if (q.empty()) break;
    	if (ar[0] == q.top().first.first &&  
    	   ar[1] == q.top().first.second && 
    	   ar[2] == q.top().second.first.first &&
    	   ar[3] == q.top().second.first.second &&
    	   ar[4] == q.top().second.second.first &&
    	   ar[5] == q.top().second.second.second) check = true;
    }
    if(check) cout << "Twin snowflakes found." << endl;
    else cout << "No two snowflakes are alike." << endl;
	return 0;
}
