#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[1000001];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
    {
        char c;
        scanf(" %c", &c);
        if(c=='S')
            A[i]=0;
        else if(c=='M')
            A[i]=1;
        else if(c=='L')
            A[i]=2;
    }
    int ans=0;
    for(int i=1; i<=M; i++)
    {
        int a;
        char c;
        scanf(" %c%d", &c, &a);
        int s;
        if(c=='S')
            s=0;
        else if(c=='M')
            s=1;
        else if(c=='L')
            s=2;
        if(1<=a && a<=N && A[a]>=s)
            ans++, A[a]=-1;
    }
    printf("%d\n", ans);
    return 0;
}
