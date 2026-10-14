#include <iostream>
#include <vector>
using namespace std;

struct edge
{
    int to;
    int index;
};

int main()
{
    int n;
    cin >> n;
    vector<vector<edge>> adj(n);
    vector<int> label(n - 1, -1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        if (adj[i].size() >= 3)
        {
            label[adj[i][0].index] = 0;
            label[adj[i][1].index] = 1;
            label[adj[i][2].index] = 2;
            l = 3;
            break;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (label[i] == -1)
            label[i] = l++;
    }
    for (const int &i : label)
        cout << i << endl;
    return 0;
}