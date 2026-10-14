#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, k;
vector<vector<int>> adj;
vector<int> depth, parent, order, ancestor;
vector<bool> used;

void dfs(int u, int p, vector<int> &path, int h)
{
    parent[u] = p;
    depth[u] = path.size();
    path.push_back(u);
    if (depth[u] >= h)
        ancestor[u] = path[depth[u] - h + 1];
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        dfs(v, u, path, h);
    }
    path.pop_back();
}

bool check(int h)
{
    vector<int> path;
    ancestor.assign(n + 1, 0);
    depth.assign(n + 1, 0);
    parent.assign(n + 1, 0);
    dfs(1, 0, path, h);
    used.assign(n + 1, false);
    int operations = 0;
    for (int u : order)
    {
        if (depth[u] <= h || used[u])
            continue;
        int v = ancestor[u];
        operations++;
        if (operations > k)
            return false;
        stack<int> st;
        st.push(v);
        while (!st.empty())
        {
            int x = st.top();
            st.pop();
            if (used[x])
                continue;
            used[x] = true;
            for (int y : adj[x])
            {
                if (y != parent[x] && !used[y])
                    st.push(y);
            }
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        adj.assign(n + 1, {});
        for (int i = 2; i <= n; i++)
        {
            int p;
            cin >> p;
            adj[p].push_back(i);
            adj[i].push_back(p);
        }
        depth.assign(n + 1, 0);
        parent.assign(n + 1, 0);
        ancestor.assign(n + 1, 0);
        vector<int> path;
        dfs(1, 0, path, 1);
        order.clear();
        for (int i = 1; i <= n; i++)
            order.push_back(i);
        sort(order.begin(), order.end(), [&](int a, int b)
             { return depth[a] > depth[b]; });
        int l = 1, r = n - 1;
        int height;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (check(m))
            {
                height = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        cout << height << endl;
    }
    return 0;
}