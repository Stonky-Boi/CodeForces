#include <iostream>
#include <vector>
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

vector<vector<int>> adj;
vector<int> height;

void dfs(int u, int p)
{
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        dfs(v, u);
        height[u] = max(height[u], height[v] + 1);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        adj.assign(n + 1, {});
        height.assign(n + 1, 0);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 0);
        long long sum = 0;
        for (int i = 1; i <= n; i++)
            sum = (sum + height[i] + 1) % MOD;
        long long total_sum = power(2, n - 1) * sum % MOD;
        cout << total_sum << endl;
    }
    return 0;
}