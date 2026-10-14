#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> color(n, -1);
    int color0 = 0, color1 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(0);
    color[0] = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (color[curr] == 0)
            color0++;
        else
            color1++;
        for (int node : adj[curr])
        {
            if (color[node] == -1)
            {
                color[node] = 1 - color[curr];
                q.push(node);
            }
        }
    }
    cout << 1ll * color0 * color1 - (n - 1) << endl;
    return 0;
}