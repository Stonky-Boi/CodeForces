#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> g(n), w(n);
        for (int i = 0; i < n; i++)
            cin >> g[i] >> w[i];
        vector<vector<int>> adj(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g[i] == g[j] || w[i] == w[j])
                    adj[i][j] = 1;
            }
        }
        int total = 1 << n;
        vector<vector<bool>> dp(total, vector<bool>(n, false));
        int best = 1;
        for (int i = 0; i < n; i++)
            dp[1 << i][i] = true;
        for (int mask = 1; mask < total; mask++)
        {
            int count = __builtin_popcount(mask);
            for (int i = 0; i < n; i++)
            {
                if (!dp[mask][i])
                    continue;
                best = max(best, count);
                for (int j = 0; j < n; j++)
                {
                    if ((mask & (1 << j)) == 0 && adj[i][j])
                    {
                        int new_mask = mask | (1 << j);
                        dp[new_mask][j] = true;
                    }
                }
            }
        }
        cout << n - best << endl;
    }
    return 0;
}