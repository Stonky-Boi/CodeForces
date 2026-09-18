#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
const int MAX_N = 200000 + 5;
const int BITS = 29;
long long factorial[MAX_N];
long long inverse_factorial[MAX_N];

long long mod_pow(long long base, long long exponent)
{
    long long result = 1;
    base %= MOD;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exponent /= 2;
    }
    return result;
}

long long ncr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    long long result = factorial[n];
    result = (result * inverse_factorial[r]) % MOD;
    result = (result * inverse_factorial[n - r]) % MOD;
    return result;
}

int main()
{
    factorial[0] = 1;
    for (int i = 1; i < MAX_N; i++)
        factorial[i] = (factorial[i - 1] * i) % MOD;
    inverse_factorial[MAX_N - 1] = mod_pow(factorial[MAX_N - 1], MOD - 2);
    for (int i = MAX_N - 1; i > 0; i--)
        inverse_factorial[i - 1] = (inverse_factorial[i] * i) % MOD;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> b(n);
        for (auto &i : b)
            cin >> i;
        vector<int> count(BITS, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int bit = 0; bit < BITS; bit++)
            {
                if (((b[i] >> bit) & 1) == 1)
                {
                    count[bit] = i + 1;
                    for (int j = 0; j <= i; j++)
                    {
                        long long subtract_value = ncr(i + 1, j + 1);
                        subtract_value = (subtract_value * (1LL << bit)) % MOD;
                        b[j] -= subtract_value;
                        if (b[j] < 0)
                            b[j] += MOD;
                    }
                }
            }
        }
        vector<int> a(n, 0);
        for (int bit = 0; bit < BITS; bit++)
            for (int i = 0; i < count[bit]; i++)
                a[i] |= (1 << bit);
        for (auto i : a)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}