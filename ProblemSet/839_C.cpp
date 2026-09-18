#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
double expected_length = 0.0;

void dfs(int node, int depth, double probability)
{
    visited[node] = true;
    int unvisited_neighbors = 0;
    for (auto neighbor : adj[node])
        if (!visited[neighbor])
            unvisited_neighbors++;
    if (unvisited_neighbors == 0)
    {
        expected_length += depth * probability;
        return;
    }
    double new_probability = probability / unvisited_neighbors;
    for (auto neighbor : adj[node])
        if (!visited[neighbor])
            dfs(neighbor, depth + 1, new_probability);
}

int main()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    visited.resize(n + 1, false);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 1.0);
    cout << fixed << setprecision(10) << expected_length << endl;
    return 0;
}