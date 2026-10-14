#include <iostream>
#include <vector>
using namespace std;

int dfs(int u, int parent, vector<vector<int>> &adj, int &removed)
{
    int size = 1;
    for (int v : adj[u])
    {
        if (v == parent)
            continue;
        size += dfs(v, u, adj, removed);
    }
    if (u != 0 && size % 2 == 0)
    {
        removed++;
        return 0;
    }
    return size;
}

int main()
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
    if (n % 2 == 1)
    {
        cout << -1 << endl;
        return 0;
    }
    int removed = 0;
    dfs(0, -1, adj, removed);
    cout << removed << endl;
    return 0;
}