#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main()
{
    set<long long> possible;
    for (long long k = 2; k <= 1e6; k++)
    {
        long long sum = 1 + k;
        long long power = k * k;
        while (true)
        {
            if (sum > 1e18 - power)
                break;
            sum += power;
            possible.insert(sum);
            if (power > 1e18 / k)
                break;
            power *= k;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if (n < 7)
        {
            cout << "NO" << endl;
            continue;
        }
        long double x = 4.0l * n - 3;
        long long root = sqrtl(x);
        bool found = false;
        for (long long r = max(0ll, root - 5); r <= root + 5; r++)
        {
            if ((long long)((long double)r * r) == 4 * n - 3)
            {
                if ((r - 1) % 2 == 0)
                {
                    long long k = (r - 1) / 2;
                    if (k > 1)
                    {
                        found = true;
                        break;
                    }
                }
            }
        }
        cout << ((found || possible.find(n) != possible.end()) ? "YES" : "NO") << endl;
    }
    return 0;
}