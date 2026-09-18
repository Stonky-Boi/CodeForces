#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int get_first(int x, const vector<set<int>> &positions, int m)
{
    if (positions[x].empty())
        return m + 1;
    return *positions[x].begin();
}

bool is_bad(int i, const vector<int> &a, const vector<set<int>> &positions, int m)
{
    if (i < 0 || i + 1 >= a.size())
        return false;
    return get_first(a[i], positions, m) > get_first(a[i + 1], positions, m);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> a(n), b(m);
        for (int &x : a)
            cin >> x;
        for (int &x : b)
            cin >> x;
        vector<int> original(n + 1);
        for (int i = 0; i < n; i++)
            original[a[i]] = i;
        vector<set<int>> positions(n + 1);
        for (int i = 0; i < m; i++)
            positions[b[i]].insert(i);
        int bad = 0;
        for (int i = 0; i + 1 < n; i++)
            bad += is_bad(i, a, positions, m);
        cout << (bad == 0 ? "YA" : "TIDAK") << endl;
        while (q--)
        {
            int s, x;
            cin >> s >> x;
            int old = b[--s];
            if (old != x)
            {
                int old_position = original[old];
                int new_position = original[x];
                vector<int> edges = {old_position - 1, old_position, new_position - 1, new_position};
                sort(edges.begin(), edges.end());
                edges.erase(unique(edges.begin(), edges.end()), edges.end());
                for (int e : edges)
                    bad -= is_bad(e, a, positions, m);
                positions[old].erase(s);
                positions[x].insert(s);
                b[s] = x;
                for (int e : edges)
                    bad += is_bad(e, a, positions, m);
            }
            cout << (bad == 0 ? "YA" : "TIDAK") << endl;
        }
    }
    return 0;
}