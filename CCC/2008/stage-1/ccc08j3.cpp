#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    char a[5][7] = {"ABCDEF", "GHIJKL", "MNOPQR", "STUVWX", "YZ -.\n"};
    char b[40];
    int row=0,col=0, distance=0;

    gets(b);
	for(int i=0; i<40 && b[i]!='\0'; i++)
		for(int x=0; x<5; x++)
			for(int y=0; y<6; y++)
				if(a[x][y]==b[i])
				{
					distance=distance + abs(x-row) + abs(y-col);
					row=x;
					col=y;
				}
	distance = distance + abs(4-row) + abs(5-col);
	cout << distance << endl;

    return 0;
}
