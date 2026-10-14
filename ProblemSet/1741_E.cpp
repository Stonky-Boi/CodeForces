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
        vector<int> b(n);
        for (int &i : b)
            cin >> i;
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] && i + b[i] + 1 <= n)
                dp[i + b[i] + 1] = true;
            if (i - b[i] >= 0 && dp[i - b[i]])
                dp[i + 1] = true;
        }
        cout << (dp[n] ? "YES" : "NO") << endl;
    }
    return 0;
}