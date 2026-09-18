#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <climits>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int nodes = 2 * n;
    vector<vector<pair<int, long long>>> adj(nodes + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v + n].push_back({u + n, w});
    }
    for (int i = 1; i <= n; i++)
        adj[i].push_back({i + n, 0});
    vector<long long> distance(nodes + 1, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    distance[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [dist, node] = pq.top();
        pq.pop();
        if (dist > distance[node])
            continue;
        for (auto [next, weight] : adj[node])
        {
            if (distance[next] > dist + weight)
            {
                distance[next] = dist + weight;
                pq.push({distance[next], next});
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (distance[i + n] == LLONG_MAX)
            cout << -1;
        else
            cout << distance[i + n];
        if (i != n)
            cout << " ";
    }
    cout << endl;
    return 0;
}