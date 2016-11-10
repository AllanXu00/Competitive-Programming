#include <iostream>
using namespace std;

int main()
{
    double a, b;
    cin >> a  >> b;
    if ( a/(b*b) < 18.5)
        cout << "Underweight\n";
    if ( a/(b*b) >= 18.5 && a/(b*b) <= 25 )
        cout << "Normal weight\n";
    if (a/(b*b) > 25)
        cout << "Overweight\n";
    return 0;
}
