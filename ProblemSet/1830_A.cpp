#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct vertex
{
    int node;
    int edge;
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<vertex>> adj(n);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
        vector<bool> visited(n, false);
        vector<int> reads(n, 1);
        queue<vertex> q;
        q.push({0, -1});
        visited[0] = true;
        int readings = 1;
        while (!q.empty())
        {
            vertex curr = q.front();
            q.pop();
            for (vertex next : adj[curr.node])
            {
                if (!visited[next.node])
                {
                    visited[next.node] = true;
                    reads[next.node] = reads[curr.node] + (next.edge < curr.edge ? 1 : 0);
                    readings = max(readings, reads[next.node]);
                    q.push(next);
                }
            }
        }
        cout << readings << endl;
    }
    return 0;
}