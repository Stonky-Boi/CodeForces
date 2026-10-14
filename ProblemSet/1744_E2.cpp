#include <iostream>
#include <vector>
#include <map>
using namespace std;

void factorize(long long x, map<long long, int> &f)
{
    for (long long p = 2; p <= x / p; p++)
    {
        while (x % p == 0)
        {
            f[p]++;
            x /= p;
        }
    }
    if (x > 1)
        f[x]++;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        long long ab = a * b;
        map<long long, int> f;
        factorize(a, f);
        factorize(b, f);
        vector<long long> divisors = {1};
        for (auto [p, e] : f)
        {
            int size = divisors.size();
            long long power = 1;
            for (int i = 1; i <= e; i++)
            {
                power *= p;
                for (int j = 0; j < size; j++)
                    divisors.push_back(divisors[j] * power);
            }
        }
        bool found = false;
        for (long long g : divisors)
        {
            long long x = (c / g) * g;
            long long k = ab / g;
            long long y = (d / k) * k;
            if (x > a && y > b)
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