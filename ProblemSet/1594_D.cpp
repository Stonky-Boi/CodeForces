#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge
{
    int to;
    bool different;
};

int bfs(int start, vector<vector<edge>> &adj, vector<int> &color)
{
    queue<int> q;
    int zeroes = 0, ones = 0;
    color[start] = 0;
    q.push(start);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (color[u] == 0)
            zeroes++;
        else
            ones++;
        for (auto [v, different] : adj[u])
        {
            int expected = color[u] ^ different;
            if (color[v] == -1)
            {
                color[v] = expected;
                q.push(v);
            }
            else if (color[v] != expected)
                return -1;
        }
    }
    return max(zeroes, ones);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<edge>> adj(n);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            string c;
            cin >> u >> v >> c;
            u--;
            v--;
            bool different = (c == "imposter");
            adj[u].push_back({v, different});
            adj[v].push_back({u, different});
        }
        vector<int> color(n, -1);
        int imposters = 0;
        bool possible = true;
        for (int i = 0; i < n; i++)
        {
            if (color[i] != -1)
                continue;
            int result = bfs(i, adj, color);
            if (result == -1)
            {
                possible = false;
                break;
            }
            imposters += result;
        }
        cout << (possible ? imposters : -1) << endl;
    }
    return 0;
}