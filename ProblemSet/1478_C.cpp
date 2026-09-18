#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> d(2 * n);
        for (auto &x : d)
            cin >> x;
        sort(d.rbegin(), d.rend());
        vector<long long> b(n); // distinct elements of d
        bool valid = true;
        for (int i = 0; i < n; ++i)
        {
            if (d[2 * i] != d[2 * i + 1])
            {
                valid = false;
                break;
            }
            b[i] = d[2 * i];
        }
        if (!valid)
        {
            cout << "NO" << endl;
            continue;
        }
        vector<long long> difference(n, 0);
        for (int i = 1; i < n; ++i)
        {
            long long delta = b[i - 1] - b[i];
            long long denom = 2 * (n - i);
            if (delta <= 0 || delta % denom != 0)
            {
                valid = false;
                break;
            }
            difference[i] = delta / denom;
        }
        if (!valid)
        {
            cout << "NO" << endl;
            continue;
        }
        long long largest = b[n - 1];
        for (int i = 1; i < n; ++i)
            largest -= 2 * i * difference[i];
        if (largest <= 0 || largest % (2 * n) != 0)
            valid = false;
        cout << (valid ? "YES" : "NO") << endl;
    }
    return 0;
}