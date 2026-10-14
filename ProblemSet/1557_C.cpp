#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

long long modpow(long long a, int b)
{
    long long result = 1;
    while (b > 0)
    {
        if (b & 1)
            result = result * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long even = modpow(2, n - 1);
        long long all = modpow(2, n);
        vector<long long> dp_equal(k + 1, 0);
        vector<long long> dp_greater(k + 1, 0);
        dp_equal[0] = 1;
        dp_greater[0] = 0;
        for (int i = 1; i <= k; i++)
        {
            dp_greater[i] = dp_greater[i - 1] * all % MOD;
            if (n % 2 == 1)
                dp_equal[i] = dp_equal[i - 1] * (even + 1) % MOD;
            else
            {
                dp_equal[i] = dp_equal[i - 1] * ((even - 1 + MOD) % MOD) % MOD;
                dp_greater[i] = (dp_greater[i] + dp_equal[i - 1]) % MOD;
            }
        }
        cout << (dp_equal[k] + dp_greater[k]) % MOD << endl;
    }
    return 0;
}