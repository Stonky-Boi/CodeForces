#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        vector<int> t(n);
        for (int i = 0; i < n; i++)
            cin >> t[i];
        sort(t.begin(), t.end());
        int INF = 1e9;
        vector<vector<int>> dp(n + 1, vector<int>(2 * n + 1, INF));
        for (int j = 0; j <= 2 * n; j++)
            dp[0][j] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= 2 * n; j++)
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(t[i - 1] - j));
        }
        cout << dp[n][2 * n] << endl;
    }
    return 0;
}