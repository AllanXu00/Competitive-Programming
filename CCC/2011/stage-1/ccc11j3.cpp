#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
   int a, b, count, temp;
   cin >> a >> b;
   vector <int> c;
   c.push_back(a);
   c.push_back(b);
   count = 2;
   while(count <10000)
   {
       temp = abs(c[count-1]-c[count-2]);
       if (temp > c [count-1])
       {
           break;
       }
       else
       {
           c.push_back(temp);
       }
       count++;
   }
   cout << count + 1;
   
   return 0;
}
