#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            string substring = s.substr(l - 1, r - l + 1);
            int length = substring.size();
            vector<int> pi(length, 0);
            vector<int> shortest(length, 0);
            vector<int> dp(length, 0);
            for (int i = 1; i < length; i++)
            {
                int j = pi[i - 1];
                while (j > 0 && substring[i] != substring[j])
                    j = pi[j - 1];
                if (substring[i] == substring[j])
                    j++;
                pi[i] = j;
                if (j == 0)
                    shortest[i] = 0;
                else if (pi[j - 1] == 0)
                    shortest[i] = j;
                else
                    shortest[i] = shortest[j - 1];
            }
            long long answer = 0;
            for (int i = 0; i < length; i++)
            {
                if (shortest[i] == 0)
                    dp[i] = 1;
                else
                    dp[i] = dp[i - shortest[i]] + 1;
                answer += dp[i];
            }
            cout << answer << endl;
        }
    }
    return 0;
}