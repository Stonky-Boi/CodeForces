#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<bool> visited(n, false);
    pq.push(0);
    visited[0] = true;
    while (!pq.empty())
    {
        int node = pq.top();
        pq.pop();
        cout << node + 1 << " ";
        for (int j : adj[node])
        {
            if (!visited[j])
            {
                visited[j] = true;
                pq.push(j);
            }
        }
    }
    cout << endl;
    return 0;
}