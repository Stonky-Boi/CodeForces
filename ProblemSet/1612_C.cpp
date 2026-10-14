#include <iostream>
using namespace std;

long long search(long long l, long long r, long long x, long long k, bool ascending)
{
    long long lines;
    while (l <= r)
    {
        long long m = l + (r - l) / 2;
        long long sum = ascending ? m * (m + 1) / 2 : m * (2 * k - m - 1) / 2;
        if (sum >= x)
        {
            lines = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    return lines;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long k, x;
        cin >> k >> x;
        if (k * k <= x)
            cout << 2 * k - 1 << endl;
        else
        {
            long long peak = k * (k + 1) / 2;
            if (x <= peak)
                cout << search(1, k, x, k, true) << endl;
            else
                cout << k + search(1, k - 1, x - peak, k, false) << endl;
        }
    }
    return 0;
}