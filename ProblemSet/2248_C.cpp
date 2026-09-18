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
        vector<int> a(2 * n + 1);
        vector<int> first(n + 1, 0), left(2 * n + 1, 0);
        for (int i = 1; i <= 2 * n; i++)
        {
            cin >> a[i];
            if (first[a[i]] == 0)
                first[a[i]] = i;
            else
                left[i] = first[a[i]];
        }
        vector<long long> dp(2 * n + 1, 0);
        for (int i = 1; i <= 2 * n; i++)
        {
            dp[i] = dp[i - 1] + 1;
            if (left[i] != 0)
            {
                int l = left[i];
                long long length = i - l + 1;
                dp[i] = max(dp[i], dp[l - 1] + length * length);
            }
        }
        cout << dp[2 * n] << endl;
    }
    return 0;
}