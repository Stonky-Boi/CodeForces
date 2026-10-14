#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int MOD = 1e9 + 7;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<long long>> dp_left(k + 1, vector<long long>(n + 2));
        vector<vector<long long>> dp_right(k + 1, vector<long long>(n + 2));
        for (int j = 0; j <= n + 1; j++)
        {
            dp_left[1][j] = 1;
            dp_right[1][j] = 1;
        }
        for (int i = 2; i <= k; i++)
        {
            dp_left[i][0] = 1;
            for (int j = 1; j <= n; j++)
                dp_left[i][j] = (dp_left[i][j - 1] + dp_right[i - 1][j + 1]) % MOD;
            dp_right[i][n + 1] = 1;
            for (int j = n; j >= 1; j--)
                dp_right[i][j] = (dp_right[i][j + 1] + dp_left[i - 1][j - 1]) % MOD;
        }
        cout << dp_right[k][1] << endl;
    }
    return 0;
}