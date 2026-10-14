#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n;
vector<long long> a, prefix_sum, dp;

bool check(long long x)
{
    deque<int> dq;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int j = i - 1;
        while (!dq.empty() && dp[dq.back()] >= dp[j])
            dq.pop_back();
        dq.push_back(j);
        while (!dq.empty() && prefix_sum[i - 1] - prefix_sum[dq.front()] > x)
            dq.pop_front();
        dp[i] = dq.empty() ? 1e18 : dp[dq.front()] + a[i];
    }
    long long best = 1e18;
    for (int i = 0; i <= n; i++)
    {
        if (prefix_sum[n] - prefix_sum[i] <= x)
            best = min(best, dp[i]);
    }
    return best <= x;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        a.assign(n + 1, 0);
        prefix_sum.assign(n + 1, 0);
        dp.assign(n + 1, 0);
        long long l = 0, r = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            prefix_sum[i] = prefix_sum[i - 1] + a[i];
            l = max(l, a[i]);
            r += a[i];
        }
        long long cost = r;
        while (l <= r)
        {
            long long m = l + (r - l) / 2;
            if (check(m))
            {
                cost = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        cout << cost << endl;
    }
    return 0;
}