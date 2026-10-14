#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long INF = 4e18;
    int n;
    cin >> n;
    vector<int> s(n);
    for (int &i : s)
        cin >> i;
    sort(s.begin(), s.end());
    vector<vector<long long>> dp(n, vector<long long>(n, INF));
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    for (int length = 2; length <= n; length++)
    {
        for (int i = 0; i + length - 1 < n; i++)
        {
            int j = i + length - 1;
            dp[i][j] = s[j] - s[i] + min(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}