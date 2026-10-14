#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

struct query
{
    int l, r, index;

    static int block;

    bool operator<(const query &other) const
    {
        int bx = l / block;
        int by = other.l / block;
        if (bx != by)
            return bx < by;
        if (bx % 2 == 0)
            return r < other.r;
        return r > other.r;
    }
};

int query::block;

int better(int x, int y, vector<int> &f)
{
    if (f[x] == f[y])
        return max(x, y);
    return (f[x] < f[y] ? x : y);
}

int get_min(int l, int r, vector<vector<int>> &sparse, vector<int> &log_2, vector<int> &f)
{
    int j = log_2[r - l + 1];
    int x = sparse[j][l];
    int y = sparse[j][r - (1 << j) + 1];
    return better(x, y, f);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        int m = n - k + 1;
        vector<int> freq(2 * n + 1, 0);
        vector<int> count(k + 1, 0);
        vector<int> f(m);
        int max_value = 0;
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
        vector<long long> F(m, 0), G(m, 0);
        stack<int> st;
        for (int i = 0; i < m; i++)
        {
            while (!st.empty() && f[st.top()] > f[i])
                st.pop();
            int p = -1;
            if (!st.empty())
                p = st.top();
            F[i] = p == -1 ? 1ll * f[i] * (i + 1) : F[p] + 1ll * f[i] * (i - p);
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i = m - 1; i >= 0; i--)
        {
            while (!st.empty() && f[st.top()] >= f[i])
                st.pop();
            int nx = m;
            if (!st.empty())
                nx = st.top();
            G[i] = nx == m ? 1ll * f[i] * (m - i) : G[nx] + 1ll * f[i] * (nx - i);
            st.push(i);
        }
        vector<int> log_2(m + 1, 0);
        for (int i = 2; i <= m; i++)
            log_2[i] = log_2[i / 2] + 1;
        int LOG = log_2[m] + 1;
        vector<vector<int>> sparse(LOG, vector<int>(m));
        for (int i = 0; i < m; i++)
            sparse[0][i] = i;
        for (int j = 1; j < LOG; j++)
        {
            for (int i = 0; i + (1 << j) <= m; i++)
            {
                int x = sparse[j - 1][i];
                int y = sparse[j - 1][i + (1 << (j - 1))];
                sparse[j][i] = better(x, y, f);
            }
        }
        vector<query> queries(q);
        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            queries[i] = {l - 1, r - k, i};
        }
        query::block = max(1, (int)sqrt(m));
        sort(queries.begin(), queries.end());
        vector<long long> f_sum(q);
        int L = 0, R = -1;
        long long sum = 0;
        for (const auto &[l, r, index] : queries)
        {
            while (L > l)
            {
                L--;
                int p = get_min(L, R, sparse, log_2, f);
                sum += G[L] - G[p] + 1ll * f[p] * (R - p + 1);
            }
            while (R < r)
            {
                R++;
                int p = get_min(L, R, sparse, log_2, f);
                sum += F[R] - F[p] + 1ll * f[p] * (p - L + 1);
            }
            while (L < l)
            {
                int p = get_min(L, R, sparse, log_2, f);
                sum -= G[L] - G[p] + 1ll * f[p] * (R - p + 1);
                L++;
            }
            while (R > r)
            {
                int p = get_min(L, R, sparse, log_2, f);
                sum -= F[R] - F[p] + 1ll * f[p] * (p - L + 1);
                R--;
            }
            f_sum[index] = sum;
        }
        for (const long long &i : f_sum)
            cout << i << endl;
    }
    return 0;
}