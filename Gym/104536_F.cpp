#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
int farthest_node;
int max_distance;

void dfs(int node, int distance)
{
    visited[node] = true;
    if (distance > max_distance)
    {
        max_distance = distance;
        farthest_node = node;
    }
    for (auto neighbor : adj[node])
        if (!visited[neighbor])
            dfs(neighbor, distance + 1);
}

int find_diameter(int n)
{
    visited.assign(n + 1, false);
    max_distance = -1;
    dfs(1, 0);
    visited.assign(n + 1, false);
    max_distance = -1;
    dfs(farthest_node, 0);
    return max_distance;
}

int main()
{
    int n, m;
    cin >> n;
    adj.assign(n + 1, {});
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int d1 = find_diameter(n);
    cin >> m;
    adj.assign(m + 1, {});
    for (int i = 0; i < m - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int d2 = find_diameter(m);
    int radius1 = (d1 + 1) / 2;
    int radius2 = (d2 + 1) / 2;
    int result = max({d1, d2, radius1 + 1 + radius2});
    cout << result << endl;
    return 0;
}