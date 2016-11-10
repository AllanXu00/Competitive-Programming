#include <iostream>

using namespace std;

int main()
{
    int c;
   string a;
   cin >> a;
   c = 0;
   for (int i = 0; i < a.length();i++)
   {
       if (a.at(i) != 'I' && a.at(i) != 'O' && a.at(i) != 'S' && a.at(i) != 'H' && a.at(i) != 'Z' && a.at(i) != 'X' && a.at(i) != 'N')
       {
           c++;
       }
   }
   if (c >0)
   {
       cout << "NO";
   }
   else
   {
       cout << "YES";
   }
   
   return 0;
}
