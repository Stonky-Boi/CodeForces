#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, x;
        cin >> n >> x;
        if ((n & x) != x)
        {
            cout << -1 << endl;
            continue;
        }
        if (n == x)
        {
            cout << n << endl;
            continue;
        }
        long long m = -1;
        for (int i = 0; i < 62; i++)
        {
            if (((n >> i) << i) == x)
            {
                long long value = x | (1ll << i);
                if (value >= n)
                    m = value;
                break;
            }
        }
        cout << m << endl;
    }
    return 0;
}