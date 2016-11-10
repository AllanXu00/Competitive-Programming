#include <iostream>
#include <algorithm>
using namespace std;

int h, m, ans = 120; char ch;

int main() {
	cin >> h >> ch >> m;
	if (h+2 >= 7 && h < 10){
		if (h>=7) ans += min((10 - h)*30 - m/2, 90); 
		else ans += min(120 - (7-h-1)*60  - 60 + m, 90);
		
	}
	if (h+2 >= 15 && h < 19){
		if (h>=15){ 
		if (m==0) m+=60;
		ans += min((19 - h)*30 - m/2, 120); 
		}
		else ans += min(120 - (15-h-1)*60  - 60 + m, 120);
	}
	printf("%02d%c%02d\n", (h+(m+ans)/60)%24, ch, (m+ans%60)%60);
	return 0;
}
