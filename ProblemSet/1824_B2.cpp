#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
int n, k;
vector<vector<int>> adj;
vector<long long> factorial, inverse_factorial;
long long expected = 1;

long long combination(int a, int b)
{
    if (b < 0 || b > a)
        return 0;
    return factorial[a] * inverse_factorial[b] % MOD * inverse_factorial[a - b] % MOD;
}

int dfs(int u, int parent)
{
    int subtree_size = 1;
    for (int v : adj[u])
    {
        if (v == parent)
            continue;
        int child_size = dfs(v, u);
        long long ways = combination(child_size, k / 2) * combination(n - child_size, k / 2) % MOD;
        expected = (expected + ways) % MOD;
        subtree_size += child_size;
    }
    return subtree_size;
}

long long power(long long a, long long b)
{
    a %= MOD;
    long long result = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            result = result * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return result;
}

int main()
{
    cin >> n >> k;
    adj.resize(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (k % 2 == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    factorial.resize(n + 1);
    inverse_factorial.resize(n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= n; i++)
        factorial[i] = factorial[i - 1] * i % MOD;
    inverse_factorial[n] = power(factorial[n], MOD - 2);
    for (int i = n; i >= 1; i--)
        inverse_factorial[i - 1] = inverse_factorial[i] * i % MOD;
    long long total_ways = combination(n, k);
    long long inverse_total = power(total_ways, MOD - 2);
    dfs(0, -1);
    expected = (expected - 1 + MOD) % MOD;
    expected = (1 + expected * inverse_total) % MOD;
    cout << expected << endl;
    return 0;
}