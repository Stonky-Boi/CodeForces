#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool found = false;
        for (int u = 1; u <= n && !found; u++)
        {
            if (adj[u].size() < 4)
                continue;
            for (int v : adj[u])
            {
                vector<int> parent(n + 1, -1);
                queue<int> q;
                parent[u] = u;
                q.push(u);
                while (!q.empty() && parent[v] == -1)
                {
                    int x = q.front();
                    q.pop();
                    for (int to : adj[x])
                    {
                        if (x == u && to == v)
                            continue;
                        if (x == v && to == u)
                            continue;
                        if (parent[to] != -1)
                            continue;
                        parent[to] = x;
                        q.push(to);
                    }
                }
                if (parent[v] == -1)
                    continue;
                vector<int> path;
                int x = v;
                while (x != u)
                {
                    path.push_back(x);
                    x = parent[x];
                }
                path.push_back(u);
                reverse(path.begin(), path.end());
                int first = path[1];
                vector<int> fins;
                for (int to : adj[u])
                {
                    if (to != v && to != first)
                        fins.push_back(to);
                    if (fins.size() == 2)
                        break;
                }
                if (fins.size() < 2)
                    continue;
                vector<pair<int, int>> edges;
                for (int i = 0; i + 1 < path.size(); i++)
                    edges.push_back({path[i], path[i + 1]});
                edges.push_back({u, v});
                edges.push_back({u, fins[0]});
                edges.push_back({u, fins[1]});
                cout << "YES" << endl;
                cout << edges.size() << endl;
                for (const auto &[a, b] : edges)
                    cout << a << " " << b << endl;
                found = true;
                break;
            }
        }
        if (!found)
            cout << "NO" << endl;
    }
    return 0;
}