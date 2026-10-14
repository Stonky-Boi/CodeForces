#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 1e18;

struct node
{
    long long distance;
    int vertex;
    int has_horse;

    bool operator>(const node &other) const
    {
        return distance > other.distance;
    }
};

vector<long long> dijkstra(int start, vector<vector<pair<int, int>>> &adj, vector<int> &a, int n)
{
    vector<vector<long long>> dist(n, vector<long long>(2, INF));
    priority_queue<node, vector<node>, greater<node>> pq;
    int state = a[start];
    dist[start][state] = 0;
    pq.push({0, start, state});
    while (!pq.empty())
    {
        auto [d, u, has_horse] = pq.top();
        pq.pop();
        if (d != dist[u][has_horse])
            continue;
        for (const auto &[v, w] : adj[u])
        {
            long long new_dist = d + (has_horse ? w / 2 : w);
            if (new_dist < dist[v][has_horse])
            {
                dist[v][has_horse] = new_dist;
                pq.push({new_dist, v, has_horse});
            }
            if (!has_horse && a[v])
            {
                if (new_dist < dist[v][1])
                {
                    dist[v][1] = new_dist;
                    pq.push({new_dist, v, 1});
                }
            }
        }
    }
    vector<long long> min_dist(n);
    for (int i = 0; i < n; i++)
        min_dist[i] = min(dist[i][0], dist[i][1]);
    return min_dist;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, h;
        cin >> n >> m >> h;
        vector<int> a(n, 0);
        for (int i = 0; i < h; i++)
        {
            int x;
            cin >> x;
            x--;
            a[x] = 1;
        }
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
        vector<long long> dist1 = dijkstra(0, adj, a, n);
        vector<long long> dist2 = dijkstra(n - 1, adj, a, n);
        long long time = INF;
        for (int i = 0; i < n; i++)
            time = min(time, max(dist1[i], dist2[i]));
        cout << (time == INF ? -1 : time) << endl;
    }
    return 0;
}