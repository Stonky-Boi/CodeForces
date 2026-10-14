#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, int p, int d, vector<vector<int>> &adj, vector<int> &depth, vector<int> &max_depth)
{
    depth[u] = d;
    max_depth[u] = d;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        dfs(v, u, d + 1, adj, depth, max_depth);
        max_depth[u] = max(max_depth[u], max_depth[v]);
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
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> depth(n), max_depth(n);
        dfs(0, -1, 0, adj, depth, max_depth);
        vector<int> diff(n + 2, 0);
        for (int i = 0; i < n; i++)
        {
            diff[depth[i]]++;
            diff[max_depth[i] + 1]--;
        }
        int curr = 0, best = 0;
        for (const int &i : diff)
        {
            curr += i;
            best = max(best, curr);
        }
        cout << n - best << endl;
    }
    return 0;
}