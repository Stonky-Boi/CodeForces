#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int MAXB = 1000;
    vector<int> d(MAXB + 1, 1e9);
    d[1] = 0;
    for (int i = 1; i <= MAXB; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            int next = i + i / j;
            if (next <= MAXB)
                d[next] = min(d[next], d[i] + 1);
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> b(n), c(n);
        for (int &i : b)
            cin >> i;
        for (int &i : c)
            cin >> i;
        k = min(k, 12 * n);
        vector<int> dp(k + 1, 0);
        for (int i = 0; i < n; i++)
        {
            int cost = d[b[i]];
            int value = c[i];
            for (int j = k; j >= cost; j--)
                dp[j] = max(dp[j], dp[j - cost] + value);
        }
        cout << dp[k] << endl;
    }
    return 0;
}