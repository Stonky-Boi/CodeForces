#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int MOD = 1e9 + 7;
    int n, k;
    cin >> n >> k;
    // dp[i][j] = number of good sequences of length i ending at j
    vector<vector<int>> dp(k + 1, vector<int>(n + 1));
    for (int j = 1; j <= n; j++)
        dp[1][j] = 1;
    for (int l = 2; l <= k; l++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j += i)
            {
                dp[l][j] += dp[l - 1][i];
                if (dp[l][j] >= MOD)
                    dp[l][j] -= MOD;
            }
        }
    }
    long long sequences = 0;
    for (int j = 1; j <= n; j++)
    {
        sequences += dp[k][j];
        sequences %= MOD;
    }
    cout << sequences << endl;
    return 0;
}