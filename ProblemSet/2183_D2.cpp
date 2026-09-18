#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dist(n + 1, -1), parent(n + 1, 0);
        vector<int> q;
        q.reserve(n);
        vector<vector<int>> levels(n + 1);
        dist[1] = 0;
        q.push_back(1);
        levels[0].push_back(1);
        int max_width = 1;
        int max_star = 0, max_depth = 0;
        int head = 0;
        while (head < q.size())
        {
            int u = q[head++];
            int children = 0;
            for (auto v : adj[u])
                if (dist[v] == -1)
                {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    levels[dist[v]].push_back(v);
                    max_depth = max(max_depth, dist[v]);
                    children++;
                    q.push_back(v);
                }
            max_star = max(max_star, children + 1);
        }
        for (int d = 0; d <= max_depth; d++)
            if ((int)levels[d].size() > max_width)
                max_width = (int)levels[d].size();
        int k = max(max_width, max_star);
        vector<int> color(n + 1, 0);
        color[1] = 1;
        vector<int> forbidden_offsets;
        forbidden_offsets.reserve(n);
        for (int d = 1; d <= max_depth; d++)
        {
            auto &nodes = levels[d];
            if (nodes.empty())
                continue;
            sort(nodes.begin(), nodes.end(), [&](int a, int b)
                 { return color[parent[a]] < color[parent[b]]; });
            forbidden_offsets.clear();
            int m = nodes.size();
            for (int i = 0; i < m; i++)
            {
                int u = nodes[i];
                int p_col = color[parent[u]];
                int bad = (p_col - 1 - i) % k;
                if (bad < 0)
                    bad += k;
                forbidden_offsets.push_back(bad);
            }
            sort(forbidden_offsets.begin(), forbidden_offsets.end());
            int best_shift = 0;
            int expected = 0;
            bool found = false;
            for (int val : forbidden_offsets)
            {
                if (val == expected)
                    expected++;
                else if (val > expected)
                {
                    best_shift = expected;
                    found = true;
                    break;
                }
            }
            if (!found)
                best_shift = expected;
            for (int i = 0; i < m; i++)
                color[nodes[i]] = ((i + best_shift) % k) + 1;
        }
        cout << k << endl;
        vector<vector<int>> ops(k + 1);
        for (int i = 1; i <= n; i++)
            ops[color[i]].push_back(i);
        for (int i = 1; i <= k; i++)
        {
            cout << ops[i].size();
            for (int u : ops[i])
                cout << " " << u;
            cout << endl;
        }
    }
    return 0;
}