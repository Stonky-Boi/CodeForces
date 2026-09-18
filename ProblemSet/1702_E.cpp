#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, const vector<vector<int>> &adj, vector<bool> &visited, int &count)
{
    visited[node] = true;
    count++;
    for (int next : adj[node])
    {
        if (!visited[next])
            dfs(next, adj, visited, count);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        vector<int> degree(n + 1, 0);
        bool possible = true;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            if (a == b)
                possible = false;
            adj[a].push_back(b);
            adj[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (degree[i] != 2)
            {
                possible = false;
                break;
            }
        }
        if (possible)
        {
            vector<bool> visited(n + 1, false);
            for (int i = 1; i <= n; i++)
            {
                if (!visited[i])
                {
                    int count = 0;
                    dfs(i, adj, visited, count);
                    if (count % 2 == 1)
                    {
                        possible = false;
                        break;
                    }
                }
            }
        }
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}