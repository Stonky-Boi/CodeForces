#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct node
{
    int min_value, max_value;
    int min_position, max_position;
};

struct segment_tree
{
    int n;
    vector<node> tree;

    node merge(node a, node b)
    {
        node result;
        if (a.min_value < b.min_value)
        {
            result.min_value = a.min_value;
            result.min_position = a.min_position;
        }
        else if (a.min_value > b.min_value)
        {
            result.min_value = b.min_value;
            result.min_position = b.min_position;
        }
        else
        {
            result.min_value = a.min_value;
            result.min_position = min(a.min_position, b.min_position);
        }
        if (a.max_value > b.max_value)
        {
            result.max_value = a.max_value;
            result.max_position = a.max_position;
        }
        else if (a.max_value < b.max_value)
        {
            result.max_value = b.max_value;
            result.max_position = b.max_position;
        }
        else
        {
            result.max_value = a.max_value;
            result.max_position = min(a.max_position, b.max_position);
        }
        return result;
    }

    void build(int v, int l, int r, vector<int> &a)
    {
        if (l == r)
        {
            tree[v] = {a[l], a[l], l, l};
            return;
        }
        int m = (l + r) / 2;
        build(2 * v, l, m, a);
        build(2 * v + 1, m + 1, r, a);
        tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    }

    void update(int v, int l, int r, int p)
    {
        if (l == r)
        {
            tree[v] = {n + 1, 0, p, p};
            return;
        }
        int m = (l + r) / 2;
        if (p <= m)
            update(2 * v, l, m, p);
        else
            update(2 * v + 1, m + 1, r, p);
        tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    }

    node query(int v, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
            return tree[v];
        int m = (l + r) / 2;
        if (qr <= m)
            return query(2 * v, l, m, ql, qr);
        if (ql > m)
            return query(2 * v + 1, m + 1, r, ql, qr);
        node x = query(2 * v, l, m, ql, qr);
        node y = query(2 * v + 1, m + 1, r, ql, qr);
        return merge(x, y);
    }

    segment_tree(vector<int> &a)
    {
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    void update(int p)
    {
        update(1, 0, n - 1, p);
    }

    node query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<vector<int>> position(n + 1);
        vector<int> last(n + 1, -1);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            position[a[i]].push_back(i);
            last[a[i]] = i;
        }
        set<pair<int, int>> s;
        for (int i = 1; i <= n; i++)
        {
            if (last[i] != -1)
                s.insert({last[i], i});
        }
        segment_tree seg(a);
        vector<int> b;
        int curr = 0;
        while (!s.empty())
        {
            node result = seg.query(curr, s.begin()->first);
            int x, p;
            if (b.size() % 2 == 0)
            {
                x = result.max_value;
                p = result.max_position;
            }
            else
            {
                x = result.min_value;
                p = result.min_position;
            }
            b.push_back(x);
            s.erase({last[x], x});
            for (const int &i : position[x])
                seg.update(i);
            curr = p + 1;
        }
        cout << b.size() << endl;
        for (const int &i : b)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}