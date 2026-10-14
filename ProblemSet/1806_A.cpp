#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int up = d - b;
        if (up < 0 || a < c - up)
            cout << -1 << endl;
        else
            cout << 2 * up + a - c << endl;
    }
    return 0;
}