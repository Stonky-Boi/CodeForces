#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;

long long power(long long a, long long b)
{
    long long result = 1;
    while (b > 0)
    {
        if (b & 1)
            result = result * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, k;
        cin >> n >> m >> k;
        long long sum = 0;
        for (int i = 0; i < m; i++)
        {
            long long a, b, f;
            cin >> a >> b >> f;
            sum = (sum + f) % MOD;
        }
        long long N = n * (n - 1) / 2;
        long long invN = power(N % MOD, MOD - 2);
        long long expected = sum * k % MOD;
        expected = expected * invN % MOD;
        long long ways = k * (k - 1) / 2 % MOD;
        long long extra = m * ways % MOD;
        extra = extra * invN % MOD;
        extra = extra * invN % MOD;
        expected = (expected + extra) % MOD;
        cout << expected << endl;
    }
    return 0;
}