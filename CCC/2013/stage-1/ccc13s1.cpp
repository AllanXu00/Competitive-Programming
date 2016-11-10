#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int digit(int a)
{
    int temp, count;
    count = 0;
    vector <int> check;
    while (a >= 1)
    {
        if (a%10==0)
        {
            temp = 0;
        }
        else
        {
        temp = a % 10;
        }
        check.push_back (temp);
        a = a - temp;
        a = a/10;
 
    }
    sort (check.begin(), check.end());
    for (int i = 0; i < check.size(); i++)
    {
        if (check [i] == check [i - 1])
        {
            count++;
        }
    }
    if (count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
   int a, b; 
   cin >> a;
   while (true)
   {
       a++;
       b = digit(a);
       if (b == 1)
       {
           cout << a << endl;
           return 0;
       }
 
   }
 
   return 0;
}
