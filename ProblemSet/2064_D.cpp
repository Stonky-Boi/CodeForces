#include <iostream>
#include <vector>
using namespace std;

class segment_tree
{
private:
    struct node
    {
        int max_value;
        int xor_value;
    };

    int n;
    vector<node> tree;

    int get_bit(int x)
    {
        return 31 - __builtin_clz(x);
    }

    node merge(node a, node b)
    {
        return {max(a.max_value, b.max_value), a.xor_value ^ b.xor_value};
    }

    void build(int i, int l, int r, const vector<int> &a)
    {
        if (l == r)
        {
            tree[i].max_value = get_bit(a[l]);
            tree[i].xor_value = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(i * 2, l, m, a);
        build(i * 2 + 1, m + 1, r, a);
        tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);
    }

    int get_xor(int i, int l, int r, int ql, int qr)
    {
        if (ql > r || qr < l)
            return 0;
        if (ql <= l && r <= qr)
            return tree[i].xor_value;
        int m = (l + r) / 2;
        return get_xor(i * 2, l, m, ql, qr) ^ get_xor(i * 2 + 1, m + 1, r, ql, qr);
    }

    int find_rightmost(int i, int l, int r, int qr, int bit)
    {
        if (l > qr || tree[i].max_value < bit)
            return -1;
        if (l == r)
            return l;
        int m = (l + r) / 2;
        int result = find_rightmost(i * 2 + 1, m + 1, r, qr, bit);
        if (result != -1)
            return result;
        return find_rightmost(i * 2, l, m, qr, bit);
    }

public:
    segment_tree(const vector<int> &a)
    {
        n = a.size() - 1;
        tree.resize(4 * n + 5);
        build(1, 1, n, a);
    }

    int range_xor(int l, int r)
    {
        if (l > r)
            return 0;
        return get_xor(1, 1, n, l, r);
    }

    int rightmost(int r, int bit)
    {
        if (r <= 0)
            return -1;
        return find_rightmost(1, 1, n, r, bit);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> w(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> w[i];
        segment_tree st(w);
        while (q--)
        {
            int x;
            cin >> x;
            int j = n;
            int eaten = 0;
            while (j >= 1 && x > 0)
            {
                int bit = 31 - __builtin_clz(x);
                int i = st.rightmost(j, bit);
                if (i == -1)
                {
                    eaten += j;
                    x ^= st.range_xor(1, j);
                    break;
                }
                if (i < j)
                {
                    eaten += j - i;
                    x ^= st.range_xor(i + 1, j);
                }
                if (w[i] > x)
                    break;
                x ^= w[i];
                eaten++;
                j = i - 1;
            }
            cout << eaten << endl;
        }
    }
    return 0;
}