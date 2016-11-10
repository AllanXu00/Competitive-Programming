#include <iostream>

using namespace std;

int main()
{
   int a, b;
   cin >> a >> b;
   if (a/b == 0 && a%b%2==0 && b%2==0)
   {
       cout << a/2 << "/" << b/2;
   }
   else if (a/b==0)
   {
       cout << a << "/" << b;
   }
   else if (a%b==0)
   {
   cout << a/b; 
   }
   else if (a%b%7==0 && b % 7 ==0)
   {
       cout << a/b << " " << (a%b)/7 << "/" << b/7;
   }
   else if (a%b%5==0 && b % 5 ==0)
   {
       cout << a/b << " " << (a%b)/5 << "/" << b/5;
   }
   else if (a%b%3==0 && b % 3 ==0)
   {
       cout << a/b << " " << (a%b)/3 << "/" << b/3;
   }
   else if (a%b%2==0 && b % 2 ==0)
   {
       cout << a/b << " " << (a%b)/2 << "/" << b/2;
   }
   
   else
   {
       cout << a/b << " " << a%b << "/" << b;
   }
   
   return 0;
}
