#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int MOD = 998244353;
    int n;
    cin >> n;
    vector<int> divisors(n + 1, 0);
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
            divisors[j]++;
    }
    dp[0] = 1;
    long long sum = dp[0];
    for (int i = 1; i <= n; i++)
    {
        dp[i] = (divisors[i] - 1 + sum) % MOD;
        sum = (sum + dp[i]) % MOD;
    }
    cout << dp[n] << endl;
    return 0;
}