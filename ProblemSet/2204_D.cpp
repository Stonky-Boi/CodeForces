#include <iostream>
#include <vector>
#include <queue>
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
        vector<int> color(n + 1, -1);
        long long beautiful = 0;
        for (int i = 1; i <= n; i++)
        {
            if (color[i] != -1)
                continue;
            if (adj[i].empty())
            {
                beautiful += 1;
                color[i] = 0;
                continue;
            }
            queue<int> q;
            q.push(i);
            color[i] = 0;
            int c0 = 1, c1 = 0;
            bool bipartite = true;
            while (!q.empty())
            {
                int v = q.front();
                q.pop();
                for (auto u : adj[v])
                {
                    if (color[u] == -1)
                    {
                        color[u] = color[v] ^ 1;
                        if (color[u] == 0)
                            c0++;
                        else
                            c1++;
                        q.push(u);
                    }
                    else if (color[u] == color[v])
                        bipartite = false;
                }
            }
            if (bipartite)
                beautiful += max(c0, c1);
        }
        cout << beautiful << endl;
    }
    return 0;
}