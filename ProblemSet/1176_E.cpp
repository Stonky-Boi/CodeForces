#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<int> dist;

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        adj.assign(n + 1, {});
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dist.assign(n + 1, -1);
        bfs(1);
        vector<int> even, odd;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] % 2 == 0)
                even.push_back(i);
            else
                odd.push_back(i);
        }
        if ((int)even.size() <= n / 2)
        {
            cout << even.size() << endl;
            for (int i = 0; i < (int)even.size(); i++)
            {
                cout << even[i];
                if (i + 1 < (int)even.size())
                    cout << " ";
            }
        }
        else
        {
            cout << odd.size() << endl;
            for (int i = 0; i < (int)odd.size(); i++)
            {
                cout << odd[i];
                if (i + 1 < (int)odd.size())
                    cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}