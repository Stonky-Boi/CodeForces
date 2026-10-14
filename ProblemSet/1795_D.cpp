#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MOD = 998244353;

long long power(long long a, long long b)
{
    long long result = 1;
    while (b)
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
    int n;
    cin >> n;
    vector<int> w(n);
    for (int &i : w)
        cin >> i;
    int triples = n / 3;
    long long ways = 1;
    for (int i = 0; i < n; i += 3)
    {
        int minimum = min({w[i], w[i + 1], w[i + 2]});
        int count = (w[i] == minimum) + (w[i + 1] == minimum) + (w[i + 2] == minimum);
        ways = ways * count % MOD;
    }
    vector<long long> factorial(triples + 1);
    factorial[0] = 1;
    for (int i = 1; i <= triples; i++)
        factorial[i] = factorial[i - 1] * i % MOD;
    int k = n / 6;
    long long colorings = factorial[triples];
    colorings = colorings * power(factorial[k], MOD - 2) % MOD;
    colorings = colorings * power(factorial[triples - k], MOD - 2) % MOD;
    ways = ways * colorings % MOD;
    cout << ways << endl;
    return 0;
}