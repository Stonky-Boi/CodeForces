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
        vector<int> s(n);
        for (int &i : s)
            cin >> i;
        vector<int> dp(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                if (s[i - 1] < s[j - 1])
                    dp[j] = max(dp[j], dp[i] + 1);
            }
        }
        int moves = 0;
        for (const int &i : dp)
            moves = max(moves, i);
        cout << moves << endl;
    }
    return 0;
}