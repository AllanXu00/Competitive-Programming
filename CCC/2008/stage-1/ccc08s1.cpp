#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int x;
    x = 0;
    pair <int, string> e [10000];
    
    for (x = 0; x < 10000; x++)
    {
        cin >> e [x].second >> e [x].first;
        if (e [x].second == "Waterloo")
        {
            break;
        }
    }
    
    sort (e, e + (x + 1));
    cout << e [0].second; 
   return 0;
}
