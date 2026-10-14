#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int, vector<int>> bfs(int start, vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int farthest = start;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (dist[u] > dist[farthest])
            farthest = u;
        for (int v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return {farthest, dist};
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
    auto [a, _] = bfs(0, adj);
    auto [b, dist_a] = bfs(a, adj);
    auto [__, dist_b] = bfs(b, adj);
    vector<int> count(n + 1, 0);
    for (int i = 0; i < n; i++)
        count[max(dist_a[i], dist_b[i])]++;
    int isolated = 0;
    for (int k = 1; k <= n; k++)
    {
        isolated += count[k - 1];
        cout << (k <= max(dist_a[b], dist_b[b]) ? isolated + 1 : n) << " ";
    }
    cout << endl;
    return 0;
}