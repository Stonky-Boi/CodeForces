#include <iostream>
#include <vector>
using namespace std;

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
            cin >> i;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> parent(n, -1), size(n, 1);
        vector<int> order = {0};
        for (int i = 0; i < order.size(); i++)
        {
            int u = order[i];
            for (int v : adj[u])
            {
                if (v == parent[u])
                    continue;
                parent[v] = u;
                order.push_back(v);
            }
        }
        long long sum = 0;
        for (int i = n - 1; i > 0; i--)
        {
            int u = order[i];
            int p = parent[u];
            size[p] += size[u];
            sum += 1ll * size[u] * (a[u] ^ a[p]);
        }
        vector<long long> m(n);
        m[0] = sum;
        for (int i = 1; i < n; i++)
        {
            int u = order[i];
            int p = parent[u];
            m[u] = m[p] + 1ll * (n - 2 * size[u]) * (a[u] ^ a[p]);
        }
        for (const long long &i : m)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}