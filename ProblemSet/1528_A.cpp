#include <iostream>
#include <vector>
using namespace std;

struct vertex
{
    int l, r;
};

vector<vertex> points;
vector<vector<int>> adj;
vector<long long> dp_l, dp_r;

void dfs(int v, int parent)
{
    for (int u : adj[v])
    {
        if (u == parent)
            continue;
        dfs(u, v);
        dp_l[v] += max(dp_l[u] + abs(points[v].l - points[u].l), dp_r[u] + abs(points[v].l - points[u].r));
        dp_r[v] += max(dp_l[u] + abs(points[v].r - points[u].l), dp_r[u] + abs(points[v].r - points[u].r));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        points.resize(n);
        for (auto &[l, r] : points)
            cin >> l >> r;
        adj.assign(n, {});
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dp_l.assign(n, 0);
        dp_r.assign(n, 0);
        dfs(0, -1);
        cout << max(dp_l[0], dp_r[0]) << endl;
    }
    return 0;
}