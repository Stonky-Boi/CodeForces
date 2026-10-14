#include <iostream>
using namespace std;

int check(int a, int b)
{
    cout << "? " << a << " " << b << endl;
    int value;
    cin >> value;
    if (value == a * b)
        return 0;
    else if (value == a * (b + 1))
        return 1;
    else
        return 2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l = 2, r = 999;
        int x;
        while (l <= r)
        {
            int a = (2 * l + r) / 3;
            int b = (2 * r + l) / 3;
            int result = check(a, b);
            if (result == 0)
                l = b + 1;
            else if (result == 1)
            {
                x = b;
                l = a + 1;
                r = b - 1;
            }
            else
            {
                x = a;
                r = a - 1;
            }
        }
        cout << "! " << x << endl;
    }
    return 0;
}