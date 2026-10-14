#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct query
{
    int l, r, index;

    bool operator<(const query &other) const
    {
        return l > other.l;
    }
};

struct node
{
    long long sum = 0;
    int tag = -1;
};

vector<node> tree;

void update_node(int v, int l, int r, int x)
{
    tree[v].sum = 1ll * (r - l + 1) * x;
    tree[v].tag = x;
}

void push(int v, int l, int r)
{
    if (tree[v].tag == -1 || l == r)
        return;
    int m = (l + r) / 2;
    update_node(v * 2, l, m, tree[v].tag);
    update_node(v * 2 + 1, m + 1, r, tree[v].tag);
    tree[v].tag = -1;
}

void update(int v, int l, int r, int ql, int qr, int x)
{
    if (ql > qr)
        return;
    if (ql <= l && r <= qr)
    {
        update_node(v, l, r, x);
        return;
    }
    push(v, l, r);
    int m = (l + r) / 2;
    if (ql <= m)
        update(v * 2, l, m, ql, qr, x);
    if (qr > m)
        update(v * 2 + 1, m + 1, r, ql, qr, x);
    tree[v].sum = tree[v * 2].sum + tree[v * 2 + 1].sum;
}

long long get_sum(int v, int l, int r, int ql, int qr)
{
    if (ql > qr)
        return 0;
    if (ql <= l && r <= qr)
        return tree[v].sum;
    push(v, l, r);
    int m = (l + r) / 2;
    long long f_sum = 0;
    if (ql <= m)
        f_sum += get_sum(v * 2, l, m, ql, qr);
    if (qr > m)
        f_sum += get_sum(v * 2 + 1, m + 1, r, ql, qr);
    return f_sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        vector<int> freq(2 * n + 1, 0);
        vector<int> count(k + 1, 0);
        int max_value = 0;
        int m = n - k + 1;
        vector<int> f(m);
        for (int i = 0; i < k; i++)
        {
            int x = a[i] - (i + 1) + n;
            if (freq[x] > 0)
                count[freq[x]]--;
            freq[x]++;
            count[freq[x]]++;
            max_value = max(max_value, freq[x]);
        }
        f[0] = k - max_value;
        for (int i = k; i < n; i++)
        {
            int x = a[i - k] - (i - k + 1) + n;
            count[freq[x]]--;
            freq[x]--;
            if (freq[x] > 0)
                count[freq[x]]++;
            int y = a[i] - (i + 1) + n;
            if (freq[y] > 0)
                count[freq[y]]--;
            freq[y]++;
            count[freq[y]]++;
            while (max_value > 0 && count[max_value] == 0)
                max_value--;
            max_value = max(max_value, freq[y]);
            f[i - k + 1] = k - max_value;
        }
        vector<query> queries(q);
        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            queries[i] = {l - 1, r - k, i};
        }
        sort(queries.begin(), queries.end());
        tree.assign(4 * m + 5, node());
        stack<int> st;
        vector<long long> f_sum(q);
        int j = m - 1;
        for (const auto &[l, r, i] : queries)
        {
            while (j >= l)
            {
                while (!st.empty() && f[st.top()] >= f[j])
                    st.pop();
                int u = m;
                if (!st.empty())
                    u = st.top();
                update(1, 0, m - 1, j, u - 1, f[j]);
                st.push(j);
                j--;
            }
            f_sum[i] = get_sum(1, 0, m - 1, l, r);
        }
        for (const long long &i : f_sum)
            cout << i << "\n"; // test case 33 TLE's on endl
    }
    return 0;
}