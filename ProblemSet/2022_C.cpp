#include <iostream>
#include <vector>
using namespace std;

int get_votes(char a, char b, char c)
{
    int count = (a == 'A') + (b == 'A') + (c == 'A');
    return count >= 2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s1, s2;
        cin >> n >> s1 >> s2;
        int NEG_INF = -1e9;
        vector<vector<int>> dp(n + 5, vector<int>(3, NEG_INF));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i][0] != NEG_INF)
            {
                if (i + 2 < n)
                {
                    int votes = get_votes(s1[i], s1[i + 1], s1[i + 2]) + get_votes(s2[i], s2[i + 1], s2[i + 2]);
                    dp[i + 3][0] = max(dp[i + 3][0], dp[i][0] + votes);
                }
                if (i + 1 < n)
                {
                    int votes = get_votes(s1[i], s2[i], s1[i + 1]);
                    dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + votes);
                    votes = get_votes(s1[i], s2[i], s2[i + 1]);
                    dp[i + 1][2] = max(dp[i + 1][2], dp[i][0] + votes);
                }
            }
            if (dp[i][1] != NEG_INF)
            {
                if (i + 3 < n)
                {
                    int votes = get_votes(s1[i + 1], s1[i + 2], s1[i + 3]) + get_votes(s2[i], s2[i + 1], s2[i + 2]);
                    dp[i + 3][1] = max(dp[i + 3][1], dp[i][1] + votes);
                }
                if (i + 1 < n)
                {
                    int votes = get_votes(s2[i], s1[i + 1], s2[i + 1]);
                    dp[i + 2][0] = max(dp[i + 2][0], dp[i][1] + votes);
                }
            }
            if (dp[i][2] != NEG_INF)
            {
                if (i + 3 < n)
                {
                    int votes = get_votes(s1[i], s1[i + 1], s1[i + 2]) + get_votes(s2[i + 1], s2[i + 2], s2[i + 3]);
                    dp[i + 3][2] = max(dp[i + 3][2], dp[i][2] + votes);
                }
                if (i + 1 < n)
                {
                    int votes = get_votes(s1[i], s1[i + 1], s2[i + 1]);
                    dp[i + 2][0] = max(dp[i + 2][0], dp[i][2] + votes);
                }
            }
        }
        cout << dp[n][0] << endl;
    }
    return 0;
}