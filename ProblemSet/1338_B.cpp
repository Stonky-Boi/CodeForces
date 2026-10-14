#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> degree(n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    int leaves = 0;
    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 1)
            leaves++;
    }
    vector<int> parent(n, -1);
    vector<int> depth(n, 0);
    vector<int> order;
    order.push_back(0);
    parent[0] = 0;
    for (int i = 0; i < order.size(); i++)
    {
        int u = order[i];
        for (int v : adj[u])
        {
            if (v == parent[u])
                continue;
            parent[v] = u;
            depth[v] = depth[u] + 1;
            order.push_back(v);
        }
    }
    int parity = -1;
    bool same = true;
    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 1)
        {
            if (parity == -1)
                parity = depth[i] % 2;
            else if (parity != depth[i] % 2)
                same = false;
        }
    }
    int min_value = same ? 1 : 3;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (degree[i] == 1)
            continue;
        bool has_leaf = false;
        for (int v : adj[i])
        {
            if (degree[v] == 1)
            {
                has_leaf = true;
                break;
            }
        }
        if (has_leaf)
            m++;
    }
    int max_value = (n - 1) - leaves + m;
    cout << min_value << " " << max_value << endl;
    return 0;
}