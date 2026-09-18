#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<vector<int>> adj;
vector<int> university;
long long max_sum = 0;

int dfs(int u, int parent)
{
    int count = university[u];
    for (int v : adj[u])
    {
        if (v == parent)
            continue;
        int child = dfs(v, u);
        max_sum += min(child, 2 * k - child);
        count += child;
    }
    return count;
}

int main()
{
    cin >> n >> k;
    adj.resize(n + 1);
    university.resize(n + 1, 0);
    for (int i = 0; i < 2 * k; i++)
    {
        int u;
        cin >> u;
        university[u] = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    cout << max_sum << endl;
    return 0;
}