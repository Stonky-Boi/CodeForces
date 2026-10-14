#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
    while (b)
    {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        long long ab = 1ll * a * b;
        bool found = false;
        for (int x = a + 1; x <= c; x++)
        {
            long long g = gcd(x, ab);
            long long k = ab / g;
            long long y = (b / k + 1) * k;
            if (y <= d)
            {
                cout << x << " " << y << endl;
                found = true;
                break;
            }
        }
        if (!found)
            cout << "-1 -1" << endl;
    }
    return 0;
}