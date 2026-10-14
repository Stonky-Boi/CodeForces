#include <iostream>
#include <vector>
using namespace std;

class DSU
{
public:
    vector<int> parent, size;

    DSU(int n)
    {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        if (k == 0)
            continue;
        int first;
        cin >> first;
        for (int j = 1; j < k; j++)
        {
            int x;
            cin >> x;
            dsu.unite(first, x);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dsu.size[dsu.find(i)] << " ";
    cout << endl;
}