#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

pair<int, vector<int>> bfs(int start, const vector<vector<int>> &adj)
{
    int n = adj.size() - 1;
    vector<int> dist(n + 1, -1);
    vector<int> parent(n + 1, -1);
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
            if (dist[v] != -1)
                continue;
            dist[v] = dist[u] + 1;
            parent[v] = u;
            q.push(v);
        }
    }
    return {farthest, parent};
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        auto [a, _] = bfs(1, adj);
        auto [b, parent] = bfs(a, adj);
        vector<int> path;
        int curr = b;
        while (curr != -1)
        {
            path.push_back(curr);
            if (curr == a)
                break;
            curr = parent[curr];
        }
        reverse(path.begin(), path.end());
        int diameter = path.size() - 1;
        vector<pair<int, int>> operations;
        if (diameter % 2 == 0)
        {
            int radius = diameter / 2;
            int center = path[radius];
            for (int diameter = 0; diameter <= radius; diameter++)
                operations.push_back({center, diameter});
        }
        else
        {
            int radius = diameter / 2;
            int center1 = path[radius];
            int center2 = path[radius + 1];
            for (int diameter = 1; diameter <= radius + 1; diameter += 2)
            {
                operations.push_back({center1, diameter});
                operations.push_back({center2, diameter});
            }
        }
        cout << operations.size() << endl;
        for (auto [v, diameter] : operations)
            cout << v << ' ' << diameter << endl;
    }
    return 0;
}