#include <iostream>
using namespace std;

bool valid(int y)
{
    cout << "? 1 " << y << endl;
    int value;
    cin >> value;
    return value == y;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        int l = 2, r = 999;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (valid(m))
                l = m + 1;
            else
            {
                x = m;
                r = m - 1;
            }
        }
        cout << "! " << x << endl;
    }
    return 0;
}