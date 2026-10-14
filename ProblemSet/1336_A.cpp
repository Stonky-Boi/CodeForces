#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> depth;
vector<int> subtree_size;

void dfs(int u, int parent)
{
    subtree_size[u] = 1;
    for (int v : adj[u])
    {
        if (v == parent)
            continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        subtree_size[u] += subtree_size[v];
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    adj.resize(n);
    depth.resize(n);
    subtree_size.resize(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    depth[0] = 0;
    dfs(0, -1);
    vector<long long> gain(n);
    for (int i = 0; i < n; i++)
        gain[i] = subtree_size[i] - depth[i] - 1;
    sort(gain.begin(), gain.end(), greater<long long>());
    long long sum = 0;
    for (int i = 0; i < n - k; i++)
        sum += gain[i];
    cout << sum << endl;
    return 0;
}