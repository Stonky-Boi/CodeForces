#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> c(n);
        for (int &i : c)
            cin >> i;
        sort(c.begin(), c.end());
        if (c[0] != 1)
        {
            cout << "NO" << endl;
            continue;
        }
        vector<bool> dp(5001, false);
        dp[1] = true;
        bool possible = true;
        for (int i = 1; i < n; i++)
        {
            if (!dp[c[i]])
            {
                possible = false;
                break;
            }
            for (int j = 5000; j >= c[i]; j--)
                dp[j] = dp[j] || dp[j - c[i]];
        }
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}