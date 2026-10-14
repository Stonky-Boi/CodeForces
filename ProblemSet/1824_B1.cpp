#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
int n, k;
vector<vector<int>> adj;
long long sum = 0;

int dfs(int u, int parent)
{
    int subtree_size = 1;
    for (int v : adj[u])
    {
        if (v == parent)
            continue;
        int child_size = dfs(v, u);
        sum = (sum + 1ll * child_size * (n - child_size)) % MOD;
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
    if (k == 1 || k == 3)
        cout << 1 << endl;
    else
    {
        dfs(0, -1);
        long long total_pairs = 1ll * n * (n - 1) / 2;
        long long inverse = power(total_pairs, MOD - 2);
        long long expected = (1 + sum * inverse) % MOD;
        cout << expected << endl;
    }
    return 0;
}