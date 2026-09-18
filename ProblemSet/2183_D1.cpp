#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dist(n + 1, -1), level_count(n + 1, 0);
        vector<int> q;
        q.reserve(n);
        dist[1] = 0;
        level_count[0] = 1;
        q.push_back(1);
        int max_width = 1, max_star = 0;
        int head = 0;
        while (head < q.size())
        {
            int u = q[head++];
            int children = 0;
            for (auto v : adj[u])
                if (dist[v] == -1)
                {
                    dist[v] = dist[u] + 1;
                    level_count[dist[v]]++;
                    max_width = max(max_width, level_count[dist[v]]);
                    children++;
                    q.push_back(v);
                }
            max_star = max(max_star, children + 1);
        }
        cout << max(max_width, max_star) << endl;
    }
    return 0;
}