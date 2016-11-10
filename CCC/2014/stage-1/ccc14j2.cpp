#include <iostream>

using namespace std;

int main()
{
    int v;
    cin >> v; 
    int a = 0;
    int b = 0;
    char c;
    for (int i = 0; i < v; i++)
    {
        cin >> c; 
        if (c == 'A')
        {
            a++;
        }
        else if (c == 'B')
        {
            b++;
        }
    }
    if (b > a)
    {
        cout << "B";
    }
    else if (a > b)
    {
        cout << "A";
    }
    else
    {
        cout << "Tie";
    }
   
   return 0;
}
