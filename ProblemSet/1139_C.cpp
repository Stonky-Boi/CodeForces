#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int MOD = 1e9 + 7;

long long power(int base, int exponent)
{
    long long result = 1;
    while (exponent > 0)
    {
        result = (result * base) % MOD;
        exponent--;
    }
    return result;
}

void bfs(vector<vector<int>> &adj, vector<bool> &visited, int i, int k, long long &sum)
{
    queue<int> q;
    q.push(i);
    visited[i] = true;
    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        for (int j : adj[node])
        {
            if (!visited[j])
            {
                q.push(j);
                visited[j] = true;
            }
        }
    }
    sum = (sum + power(count, k)) % MOD;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        u--;
        v--;
        if (x == 0)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    long long bad = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        bfs(adj, visited, i, k, bad);
    }
    long long sequences = (power(n, k) - bad + MOD) % MOD;
    cout << sequences << endl;
    return 0;
}