#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> &adj, vector<bool> &visited, int start, int &bamboos, int &cycles)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    bool bamboo = false;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (adj[u].size() == 1)
            bamboo = true;
        for (int v : adj[u])
        {
            if (visited[v])
                continue;
            visited[v] = true;
            q.push(v);
        }
    }
    if (bamboo)
        bamboos++;
    else
        cycles++;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a)
        {
            cin >> i;
            i--;
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            int j = a[i];
            if (a[j] == i && i > j)
                continue;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        vector<bool> visited(n, false);
        int bamboos = 0;
        int cycles = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                bfs(adj, visited, i, bamboos, cycles);
        }
        int minimum = cycles + min(bamboos, 1);
        int maximum = cycles + bamboos;
        cout << minimum << " " << maximum << endl;
    }
    return 0;
}