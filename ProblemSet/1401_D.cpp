#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int MOD = 1e9 + 7;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
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
        vector<int> parent(n, -1);
        vector<int> order;
        order.push_back(0);
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
        vector<long long> subtree(n, 1);
        vector<long long> edges;
        for (int i = n - 1; i > 0; i--)
        {
            int u = order[i];
            edges.push_back(subtree[u] * (n - subtree[u]));
            subtree[parent[u]] += subtree[u];
        }
        int m;
        cin >> m;
        vector<long long> factors(m);
        for (int i = 0; i < m; i++)
            cin >> factors[i];
        sort(edges.begin(), edges.end(), greater<long long>());
        sort(factors.begin(), factors.end());
        if (m < n - 1)
        {
            while (factors.size() < n - 1)
                factors.insert(factors.begin(), 1);
        }
        else if (m > n - 1)
        {
            long long product = 1;
            for (int i = n - 2; i < m; i++)
                product = (product * factors[i]) % MOD;
            factors.resize(n - 2);
            factors.push_back(product);
        }
        reverse(factors.begin(), factors.end());
        long long index = 0;
        for (int i = 0; i < n - 1; i++)
            index = (index + edges[i] * factors[i]) % MOD;
        cout << index << endl;
    }
    return 0;
}