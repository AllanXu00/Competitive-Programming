#include <iostream>
#include <vector>

using namespace std;

vector< vector<long long int> > cache(251, vector<long long int>(251, -1));
long long int junior5(int n, int k)
{
    if(n < k)
        return 0;
    if(k == 1 || k == n)
        return 1;
    if(cache[n][k] != -1)
        return cache[n][k];
    cache[n][k] = junior5(n - 1, k - 1) + junior5(n - k, k);
    return cache[n][k];
}

int main()
{
    int a, b;
    scanf("%d\n%d", &a, &b);
    printf("%lld", junior5(a, b));
    return 0;
}
