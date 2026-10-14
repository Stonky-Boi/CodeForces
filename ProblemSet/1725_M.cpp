#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

const long long INF = 4e18;

vector<long long> dijkstra(vector<vector<pair<int, int>>> &adj, vector<long long> dist)
{
    int n = adj.size();
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] != INF)
            pq.push({dist[i], i});
    }
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u])
            continue;
        for (auto [v, w] : adj[u])
        {
            if (d + w < dist[v])
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n), rev_adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
        rev_adj[v].push_back({u, w});
    }
    vector<long long> dist(n, INF);
    dist[0] = 0;
    vector<long long> d = dijkstra(adj, dist);
    vector<long long> D = dijkstra(rev_adj, d);
    for (int i = 1; i < n; i++)
        cout << (D[i] == INF ? -1 : D[i]) << " ";
    cout << endl;
    return 0;
}