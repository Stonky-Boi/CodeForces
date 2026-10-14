#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> a(n + 1, 0);
    for (int i = 0; i < q; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        adj[u].push_back({v, x});
        if (u != v)
            adj[v].push_back({u, x});
    }
    for (int bit = 0; bit < 30; bit++)
    {
        vector<int> b(n + 1, 1);
        vector<bool> fixed(n + 1, false);
        for (int u = 1; u <= n; u++)
        {
            for (const auto &[v, x] : adj[u])
            {
                if (!(x & (1 << bit)))
                {
                    b[u] = 0;
                    b[v] = 0;
                }
                else if (u == v)
                    fixed[u] = true;
            }
        }
        for (int u = 1; u <= n; u++)
        {
            if (!b[u] || fixed[u])
                continue;
            bool possible = true;
            for (const auto &[v, x] : adj[u])
            {
                if ((x & (1 << bit)) && !b[v])
                {
                    possible = false;
                    break;
                }
            }
            if (possible)
                b[u] = 0;
        }
        for (int u = 1; u <= n; u++)
        {
            if (b[u])
                a[u] |= (1 << bit);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}