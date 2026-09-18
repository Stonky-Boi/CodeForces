#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;
vector<vector<int>> adj;
vector<vector<int>> episodes;

bool dfs(int node, int parent)
{
    visited[node] = true;
    vector<int> curr;
    for (auto neighbour : adj[node])
    {
        if (neighbour == parent)
            continue;
        if (visited[neighbour] && node < neighbour)
            curr.push_back(neighbour);
        if (!visited[neighbour] && dfs(neighbour, node))
            curr.push_back(neighbour);
    }
    for (int i = 0; i + 1 < (int)curr.size(); i += 2)
        episodes.push_back({curr[i], node, curr[i + 1]});
    if (curr.size() % 2 == 0)
        return true;
    if (parent != -1)
        episodes.push_back({curr.back(), node, parent});
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    adj.assign(n + 1, {});
    visited.assign(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs(i, -1);
    cout << episodes.size() << endl;
    for (auto e : episodes)
        cout << e[0] << " " << e[1] << " " << e[2] << endl;
}