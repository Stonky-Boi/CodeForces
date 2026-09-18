#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

vector<set<int>> missing;
set<int> unvisited;

void dfs(int start, int &size)
{
    stack<int> st;
    st.push(start);
    unvisited.erase(start);
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        size++;
        auto it = unvisited.begin();
        while (it != unvisited.end())
        {
            int v = *it;
            if (missing[u].count(v))
            {
                it = unvisited.upper_bound(v);
                continue;
            }
            st.push(v);
            it = unvisited.erase(it);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    missing.assign(n + 1, {});
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        missing[x].insert(y);
        missing[y].insert(x);
    }
    for (int i = 1; i <= n; i++)
        unvisited.insert(i);
    vector<int> component_sizes;
    for (int i = 1; i <= n; i++)
        if (unvisited.count(i))
        {
            int size = 0;
            dfs(i, size);
            component_sizes.push_back(size);
        }
    sort(component_sizes.begin(), component_sizes.end());
    cout << (int)component_sizes.size() << endl;
    for (int i = 0; i < (int)component_sizes.size(); i++)
    {
        cout << component_sizes[i];
        if (i + 1 < (int)component_sizes.size())
            cout << " ";
    }
    cout << endl;
    return 0;
}