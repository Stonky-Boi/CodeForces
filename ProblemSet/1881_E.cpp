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
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = 1 + dp[i + 1];
            int j = i + a[i] + 1;
            if (j <= n)
                dp[i] = min(dp[i], dp[j]);
        }
        cout << dp[0] << endl;
    }
    return 0;
}