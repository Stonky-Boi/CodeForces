#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ways = 0;
        if (n < 3)
            ways = 0;
        else if (n % 2 == 0)
            ways = n / 2 - 1;
        else
            ways = n / 2;
        cout << ways << endl;
    }
    return 0;
}