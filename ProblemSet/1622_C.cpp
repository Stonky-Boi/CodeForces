#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long divide(long long a, long long b)
{
    if (a >= 0)
        return a / b;
    return -((-a + b - 1) / b);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> a(n);
        for (long long &i : a)
            cin >> i;
        sort(a.begin(), a.end());
        long long total = 0;
        for (long long i : a)
            total += i;
        if (total <= k)
        {
            cout << 0 << endl;
            continue;
        }
        long long steps = total - k;
        long long suffix = 0;
        for (int count = 1; count <= n; count++)
        {
            if (count > 1)
                suffix += a[n - count + 1];
            long long remaining = total - a[0] - suffix;
            long long i = divide(k - remaining, count);
            i = min(i, a[0]);
            long long operations = (count - 1) + (a[0] - i);
            steps = min(steps, operations);
        }
        cout << steps << endl;
    }
    return 0;
}