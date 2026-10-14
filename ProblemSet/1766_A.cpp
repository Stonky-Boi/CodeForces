#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int digits = log10(n);
        int round = digits * 9 + n / pow(10, digits);
        cout << round << endl;
    }
    return 0;
}