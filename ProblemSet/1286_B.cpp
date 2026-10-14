#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> c;
vector<int> a;
bool valid = true;

vector<int> dfs(int u)
{
    vector<int> order;
    for (int v : adj[u])
    {
        vector<int> temp = dfs(v);
        for (int x : temp)
            order.push_back(x);
    }
    if (c[u] > order.size())
    {
        valid = false;
        return order;
    }
    order.insert(order.begin() + c[u], u);
    return order;
}

int main()
{
    int n;
    cin >> n;
    adj.resize(n);
    c.resize(n);
    a.resize(n);
    int root = -1;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p >> c[i];
        if (p == 0)
            root = i;
        else
            adj[p - 1].push_back(i);
    }
    vector<int> order = dfs(root);
    if (!valid)
    {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
        a[order[i]] = i + 1;
    cout << "YES" << endl;
    for (const int &i : a)
        cout << i << " ";
    cout << endl;
    return 0;
}