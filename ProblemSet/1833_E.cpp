#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

const int MAXN = 200000;
vector<set<int>> adj;
vector<bool> visited;
vector<int> degree_list;

void bfs(int start, int &paths, int &cycles)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    vector<int> component;
    component.push_back(start);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
                component.push_back(v);
            }
    }
    bool degree_one = false;
    for (auto node : component)
        if (degree_list[node] == 1)
        {
            degree_one = true;
            break;
        }
    if (degree_one)
        paths++;
    else
        cycles++;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        adj.assign(n, {});
        visited.assign(n, false);
        degree_list.assign(n, 0);
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i]--;
            adj[i].insert(a[i]);
            adj[a[i]].insert(i);
        }
        for (int i = 0; i < n; i++)
            degree_list[i] = (int)adj[i].size();
        int paths = 0, cycles = 0;
        for (int i = 0; i < n; i++)
            if (!visited[i])
                bfs(i, paths, cycles);
        int min_dances = cycles + min(paths, 1);
        int max_dances = cycles + paths;
        cout << min_dances << " " << max_dances << endl;
    }
    return 0;
}