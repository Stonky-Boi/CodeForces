#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    long long distance;
    int city;
    int slowness;

    bool operator>(const node &other) const
    {
        return distance > other.distance;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> s(n);
        for (int &i : s)
            cin >> i;
        long long INF = 1e18;
        vector<vector<long long>> dist(n, vector<long long>(1001, INF));
        priority_queue<node, vector<node>, greater<node>> pq;
        dist[0][s[0]] = 0;
        pq.push({0, 0, s[0]});
        while (!pq.empty())
        {
            auto [d, u, curr_s] = pq.top();
            pq.pop();
            if (d != dist[u][curr_s])
                continue;
            for (auto [v, w] : adj[u])
            {
                long long new_dist = d + 1ll * w * curr_s;
                int new_s = min(curr_s, s[v]);
                if (new_dist < dist[v][new_s])
                {
                    dist[v][new_s] = new_dist;
                    pq.push({new_dist, v, new_s});
                }
            }
        }
        long long time = INF;
        for (int i = 1; i <= 1000; i++)
            time = min(time, dist[n - 1][i]);
        cout << time << endl;
    }
    return 0;
}