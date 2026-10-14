#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e18;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, y;
        cin >> u >> v >> y;
        u--;
        v--;
        adj[u].push_back({v, y});
        adj[v].push_back({u, y});
    }
    vector<long long> d(n, INF);
    vector<bool> visited(n, false);
    d[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && (u == -1 || d[j] < d[u]))
                u = j;
        }
        if (u == -1 || d[u] == INF)
            break;
        visited[u] = true;
        for (auto [v, w] : adj[u])
            d[v] = min(d[v], d[u] + w);
    }
    if (d[n - 1] == INF)
    {
        cout << "inf" << endl;
        return 0;
    }
    long long D = d[n - 1];
    vector<long long> values(n);
    for (int i = 0; i < n; i++)
        values[i] = min(d[i], D);
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    cout << D << ' ' << values.size() - 1 << endl;
    for (int i = 0; i + 1 < values.size(); i++)
    {
        long long x = values[i];
        long long y = values[i + 1];
        string s(n, '0');
        for (int j = 0; j < n; j++)
        {
            if (min(d[j], D) <= x)
                s[j] = '1';
        }
        cout << s << ' ' << y - x << endl;
    }
    return 0;
}