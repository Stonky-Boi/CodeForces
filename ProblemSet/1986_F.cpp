#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> tin, low, sz;
int timer, n;
long long pairs;

void dfs(int u, int p, int id)
{
    timer++;
    tin[u] = low[u] = timer;
    sz[u] = 1;
    for (const auto &[v, i] : adj[u])
    {
        if (i == id)
            continue;
        if (tin[v] != 0)
            low[u] = min(low[u], tin[v]);
        else
        {
            dfs(v, u, i);
            low[u] = min(low[u], low[v]);
            sz[u] += sz[v];
            if (low[v] > tin[u])
            {
                long long s = sz[v];
                long long other = n - s;
                long long curr = s * (s - 1) / 2 + other * (other - 1) / 2;
                pairs = min(pairs, curr);
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> n >> m;
        adj.assign(n, {});
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
        tin.assign(n, 0);
        low.assign(n, 0);
        sz.assign(n, 0);
        timer = 0;
        pairs = 1ll * n * (n - 1) / 2;
        dfs(0, -1, -1);
        cout << pairs << endl;
    }
    return 0;
}