#include <iostream>
#include <vector>
using namespace std;

long long gcd(long long a, long long b)
{
    while (b)
    {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n + 1), v(n + 1, 0);
        vector<vector<int>> children(n + 1);
        vector<int> dp(n + 1, 0);
        for (int i = n; i >= 1; i--)
        {
            int k;
            cin >> a[i] >> k;
            children[i].resize(k);
            for (int &j : children[i])
                cin >> j;
            long long curr_lcm = 1;
            bool can_extend = false;
            vector<long long> valid_gcds;
            for (int j : children[i])
            {
                dp[i] += dp[j];
                long long g = gcd(v[j], a[i]);
                if (g > 1)
                {
                    can_extend = true;
                    valid_gcds.push_back(g);
                }
            }
            if (can_extend)
            {
                for (long long g : valid_gcds)
                    curr_lcm = lcm(curr_lcm, g);
                v[i] = curr_lcm;
            }
            else
            {
                dp[i] += 1;
                v[i] = a[i];
            }
            cout << dp[i] << endl;
        }
    }
    return 0;
}