#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int add_mod(int x, int y)
{
    x += y;
    if (x >= MOD)
        x -= MOD;
    return x;
}

int main()
{
    int t;
    cin >> t;
    const int max_m = 3000;
    vector<vector<int>> divisors(max_m + 1);
    for (int i = 1; i <= max_m; i++)
        for (int j = i; j <= max_m; j += i)
            divisors[j].push_back(i);
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        if (a[1] != 0 && a[1] != 1)
        {
            cout << 0 << endl;
            continue;
        }
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[1][1] = 1;
        for (int i = 1; i < n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (dp[i][j] == 0)
                    continue;
                if (a[i] != 0 && a[i] != j)
                    continue;
                for (int d : divisors[j])
                {
                    int next_value = j + d;
                    if (next_value > m)
                        continue;
                    if (a[i + 1] != 0 && a[i + 1] != next_value)
                        continue;
                    dp[i + 1][next_value] = add_mod(dp[i + 1][next_value], dp[i][j]);
                }
            }
        int answer = 0;
        for (int i = 1; i <= m; i++)
        {
            if (a[n] != 0 && a[n] != i)
                continue;
            answer = add_mod(answer, dp[n][i]);
        }
        cout << answer << endl;
    }
    return 0;
}