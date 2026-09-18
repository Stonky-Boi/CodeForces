#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> color;
long long count1 = 0, count2 = 0;

void dfs(int u, int c)
{
    color[u] = c;
    if (c == 1)
        count1++;
    else
        count2++;
    for (auto v : adj[u])
        if (color[v] == 0)
            dfs(v, 3 - c);
}

int main()
{
    int n;
    cin >> n;
    adj.assign(n + 1, {});
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    color.assign(n + 1, 0);
    dfs(1, 1);
    long long edges = count1 * count2 - (n - 1);
    cout << edges << endl;
    return 0;
}