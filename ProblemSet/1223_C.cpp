#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b)
{
    while (b)
    {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

bool can(int m, const vector<long long> &p, int x, int a, int y, int b, long long k)
{
    long long l = lcm(a, b);
    int both = m / l;
    int only_a = m / a - both;
    int only_b = m / b - both;
    if (x < y)
    {
        swap(x, y);
        swap(only_a, only_b);
    }
    long long total = 0;
    int index = 0;
    for (int i = 0; i < both; i++)
        total += p[index++] * (x + y) / 100;
    for (int i = 0; i < only_a; i++)
        total += p[index++] * x / 100;
    for (int i = 0; i < only_b; i++)
        total += p[index++] * y / 100;
    return total >= k;
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        vector<long long> p(n);
        for (auto &i : p)
            cin >> i;
        sort(p.begin(), p.end(), greater<>());
        int x, a, y, b;
        cin >> x >> a;
        cin >> y >> b;
        long long k;
        cin >> k;
        int l = 1, r = n;
        int tickets = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (can(m, p, x, a, y, b, k))
            {
                tickets = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        cout << tickets << endl;
    }
    return 0;
}