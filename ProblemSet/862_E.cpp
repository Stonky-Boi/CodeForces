#include <iostream>
#include <vector>
using namespace std;

long long find_min(long long c, const vector<long long> &b_values)
{
    int n = b_values.size();
    int l = 0, r = n - 1, ans = n;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (b_values[m] >= c)
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    long long best = LLONG_MAX;
    if (ans < n)
    {
        long long diff = b_values[ans] - c;
        if (diff < 0)
            diff = -diff;
        if (diff < best)
            best = diff;
    }
    if (ans > 0)
    {
        long long diff = b_values[ans - 1] - c;
        if (diff < 0)
            diff = -diff;
        if (diff < best)
            best = diff;
    }
    return best;
}

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    long a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    long long a_sum = 0;
    for (int i = 0; i < n; i++)
        a_sum += ((i % 2 == 0) ? a[i] : -a[i]);
    long long b_prefix[m + 1];
    b_prefix[0] = 0;
    for (int i = 0; i < m; i++)
        b_prefix[i + 1] = b_prefix[i] + ((i % 2 == 0) ? b[i] : -b[i]);
    vector<long long> b_values;
    for (int j = 0; j <= m - n; j++)
    {
        long long value = b_prefix[j + n] - b_prefix[j];
        if (j % 2 == 1)
            value = -value;
        b_values.push_back(value);
    }
    sort(b_values.begin(), b_values.end());
    cout << find_min(a_sum, b_values) << endl;
    while (q--)
    {
        int l, r;
        long x;
        cin >> l >> r >> x;
        int len = r - l + 1;
        if (len % 2 == 1)
            a_sum += ((l % 2 == 0) ? -x : x);
        cout << find_min(a_sum, b_values) << endl;
    }
    return 0;
}