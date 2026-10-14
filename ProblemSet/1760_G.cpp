#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        a--;
        b--;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        set<int> s;
        queue<pair<int, int>> q;
        vector<bool> visited(n, false);
        q.push({b, 0});
        visited[b] = true;
        while (!q.empty())
        {
            auto [u, x] = q.front();
            q.pop();
            if (u != b)
                s.insert(x);
            for (auto [v, w] : adj[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push({v, x ^ w});
                }
            }
        }
        if (s.count(0))
        {
            cout << "YES" << endl;
            continue;
        }
        while (!q.empty())
            q.pop();
        fill(visited.begin(), visited.end(), false);
        q.push({a, 0});
        visited[a] = true;
        bool possible = false;
        while (!q.empty())
        {
            auto [u, x] = q.front();
            q.pop();
            if (u == b)
                continue;
            if (s.count(x))
            {
                possible = true;
                break;
            }
            for (auto [v, w] : adj[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push({v, x ^ w});
                }
            }
        }
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}