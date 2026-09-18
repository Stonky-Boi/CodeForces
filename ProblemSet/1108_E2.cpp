#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct segment
{
    int l, r;
};

struct node
{
    long long min_value;
    int position;
    long long lazy;
};

class segment_tree
{
private:
    int n;
    vector<node> tree;

    void build(int node, int l, int r, const vector<long long> &a)
    {
        if (l == r)
        {
            tree[node] = {a[l], l, 0};
            return;
        }
        int m = (l + r) / 2;
        build(node * 2, l, m, a);
        build(node * 2 + 1, m + 1, r, a);
        pull(node);
    }

    void apply(int node, long long value)
    {
        tree[node].min_value += value;
        tree[node].lazy += value;
    }

    void push(int node)
    {
        if (tree[node].lazy != 0)
        {
            apply(node * 2, tree[node].lazy);
            apply(node * 2 + 1, tree[node].lazy);
            tree[node].lazy = 0;
        }
    }

    void pull(int node)
    {
        if (tree[node * 2].min_value <= tree[node * 2 + 1].min_value)
        {
            tree[node].min_value = tree[node * 2].min_value;
            tree[node].position = tree[node * 2].position;
        }
        else
        {
            tree[node].min_value = tree[node * 2 + 1].min_value;
            tree[node].position = tree[node * 2 + 1].position;
        }
    }

    void add(int node, int l, int r, int ql, int qr, long long value)
    {
        if (qr < l || r < ql)
            return;
        if (ql <= l && r <= qr)
        {
            apply(node, value);
            return;
        }
        push(node);
        int m = (l + r) / 2;
        add(node * 2, l, m, ql, qr, value);
        add(node * 2 + 1, m + 1, r, ql, qr, value);
        pull(node);
    }

public:
    segment_tree(const vector<long long> &a)
    {
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    void add(int l, int r, long long value)
    {
        add(1, 0, n - 1, l, r, value);
    }

    long long get_minimum()
    {
        return tree[1].min_value;
    }

    int get_minimum_position()
    {
        return tree[1].position;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (long long &i : a)
        cin >> i;
    vector<segment> segments(m);
    vector<vector<int>> starts(n);
    vector<vector<int>> ends(n);
    vector<long long> diff(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        segments[i] = {l, r};
        starts[l].push_back(i);
        ends[r].push_back(i);
        diff[l]--;
        if (r + 1 < n)
            diff[r + 1]++;
    }
    vector<long long> b(n);
    long long curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr += diff[i];
        b[i] = a[i] + curr;
    }
    segment_tree st(b);
    long long best = -(1ll << 60);
    int best_max = -1;
    for (int i : starts[0])
    {
        auto [l, r] = segments[i];
        st.add(l, r, +1);
    }
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            for (int j : ends[i - 1])
            {
                auto [l, r] = segments[j];
                st.add(l, r, -1);
            }
            for (int j : starts[i])
            {
                auto [l, r] = segments[j];
                st.add(l, r, +1);
            }
        }
        long long curr = a[i] - st.get_minimum();
        if (curr > best)
        {
            best = curr;
            best_max = i;
        }
    }
    vector<int> answer;
    for (int i = 0; i < m; i++)
    {
        int l = segments[i].l;
        int r = segments[i].r;
        if (!(l <= best_max && best_max <= r))
            answer.push_back(i + 1);
    }
    cout << best << endl;
    cout << answer.size() << endl;
    for (int i : answer)
        cout << i << ' ';
    cout << endl;
    return 0;
}