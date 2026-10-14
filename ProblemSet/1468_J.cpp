#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge
{
    int u, v;
    long long w;

    bool operator<(const edge &other) const
    {
        return w < other.w;
    }
};

struct DSU
{
    vector<int> parent, size;

    DSU(int n)
    {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (size[u] < size[v])
            swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        return true;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        long long k;
        cin >> n >> m >> k;
        vector<edge> e(m);
        long long changes = 4e18;
        for (auto &[u, v, w] : e)
        {
            cin >> u >> v >> w;
            changes = min(changes, abs(w - k));
        }
        sort(e.begin(), e.end());
        DSU d1(n);
        int count = 0;
        for (const auto &[u, v, w] : e)
        {
            if (w > k)
                break;
            if (d1.unite(u, v))
                count++;
        }
        if (count == n - 1)
        {
            cout << changes << endl;
            continue;
        }
        DSU d2(n);
        changes = 0;
        count = 0;
        for (const auto &[u, v, w] : e)
        {
            if (d2.unite(u, v))
            {
                changes += max(0LL, w - k);
                count++;
                if (count == n - 1)
                    break;
            }
        }
        cout << changes << endl;
    }
    return 0;
}