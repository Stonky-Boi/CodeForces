#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n), p(n + 1, 0);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] + a[i];
    long long l = 0, r = 1000000000;
    while (l < r)
    {
        long long m = l + (r - l) / 2;
        bool can = false;
        for (int lp = 0; lp < n; ++lp)
        {
            int rp = upper_bound(a.begin(), a.end(), a[lp] + m) - a.begin();
            long long steps_needed = (long long)lp * a[lp] - p[lp] + p[n] - p[rp] - (long long)(n - rp) * (a[lp] + m);
            if (steps_needed <= k)
            {
                can = true;
                break;
            }
        }
        if (!can)
        {
            for (int rp = 0; rp < n; ++rp)
            {
                int lp = lower_bound(a.begin(), a.end(), a[rp] - m) - a.begin();
                long long steps_needed = (long long)lp * (a[rp] - m) - p[lp] + p[n] - p[rp] - (long long)(n - rp) * a[rp];
                if (steps_needed <= k)
                {
                    can = true;
                    break;
                }
            }
        }
        if (can)
            r = m;
        else
            l = m + 1;
    }
    cout << l << endl;
    return 0;
}