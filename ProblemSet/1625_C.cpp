#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> d(n), a(n);
    for (int &i : d)
        cin >> i;
    for (int &i : a)
        cin >> i;
    d.push_back(l);
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 1e18 / 4));
    for (int i = 0; i <= k; i++)
        dp[n][i] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int removed = 0; removed <= k; removed++)
        {
            for (int j = i + 1; j <= min(i + 1 + removed, n); j++)
            {
                int extra = j - i - 1;
                long long cost = 1ll * a[i] * (d[j] - d[i]) + dp[j][removed - extra];
                dp[i][removed] = min(dp[i][removed], cost);
            }
        }
    }
    cout << dp[0][k] << endl;
    return 0;
}