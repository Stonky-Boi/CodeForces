#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 998244353;
const int MAXA = 1e6;

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
    vector<bool> prime(MAXA + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= MAXA; i++)
    {
        if (!prime[i])
            continue;
        for (int j = i * i; j <= MAXA; j += i)
            prime[j] = false;
    }
    int n;
    cin >> n;
    vector<int> a(2 * n);
    vector<int> freq(MAXA + 1, 0);
    for (int &i : a)
    {
        cin >> i;
        freq[i]++;
    }
    vector<long long> factorial(2 * n + 1);
    vector<long long> inv_factorial(2 * n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= 2 * n; i++)
        factorial[i] = factorial[i - 1] * i % MOD;
    inv_factorial[2 * n] = power(factorial[2 * n], MOD - 2);
    for (int i = 2 * n; i >= 1; i--)
        inv_factorial[i - 1] = inv_factorial[i] * i % MOD;
    vector<int> primes;
    long long non_prime_ways = 1;
    int distinct_primes = 0;
    for (int i = 1; i <= MAXA; i++)
    {
        if (freq[i] == 0)
            continue;
        if (prime[i])
        {
            primes.push_back(freq[i]);
            distinct_primes++;
        }
        else
            non_prime_ways = non_prime_ways * inv_factorial[freq[i]] % MOD;
    }
    if (distinct_primes < n)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    int processed = 0;
    for (const int &i : primes)
    {
        for (int j = min(n, processed + 1); j >= 0; j--)
        {
            long long ways = dp[j] * inv_factorial[i] % MOD;
            if (j > 0)
                ways = (ways + dp[j - 1] * inv_factorial[i - 1]) % MOD;
            dp[j] = ways;
        }
        processed++;
    }
    long long m = factorial[n] * non_prime_ways % MOD;
    m = m * dp[n] % MOD;
    cout << m << endl;
    return 0;
}