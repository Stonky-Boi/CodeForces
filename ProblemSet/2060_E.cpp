#include <iostream>
#include <vector>
#include <set>
using namespace std;

class disjoint_set
{
private:
    vector<int> parent;
    vector<int> size;

public:
    disjoint_set(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m1, m2;
        cin >> n >> m1 >> m2;
        vector<pair<int, int>> edges_f(m1), edges_g(m2);
        for (auto &[u, v] : edges_f)
            cin >> u >> v;
        for (auto &[u, v] : edges_g)
            cin >> u >> v;
        disjoint_set dsu_f(n), dsu_g(n);
        int bad_edges = 0;
        for (auto [u, v] : edges_g)
            dsu_g.union_sets(u, v);
        for (auto [u, v] : edges_f)
        {
            if (dsu_g.find_set(u) != dsu_g.find_set(v))
                bad_edges++;
            else
                dsu_f.union_sets(u, v);
        }
        vector<set<int>> comp(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int g_root = dsu_g.find_set(i);
            int f_root = dsu_f.find_set(i);
            comp[g_root].insert(f_root);
        }
        int add_edges = 0;
        for (int i = 1; i <= n; i++)
            if (!comp[i].empty())
                add_edges += (int)comp[i].size() - 1;
        cout << bad_edges + add_edges << endl;
    }
    return 0;
}