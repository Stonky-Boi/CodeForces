#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, q;
        cin >> n >> m >> q;
        long long a[n], b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        sort(a, a + n, greater<long long>());
        sort(b, b + m, greater<long long>());
        long long prefix_a[n + 1], prefix_b[m + 1];
        prefix_a[0] = 0;
        prefix_b[0] = 0;
        for (int i = 0; i < n; i++)
            prefix_a[i + 1] = prefix_a[i] + a[i];
        for (int i = 0; i < m; i++)
            prefix_b[i + 1] = prefix_b[i] + b[i];
        pair<int, int> best_split[n + m + 1];
        int l = 0, r = 0;
        for (int i = 1; i <= n + m; i++)
        {
            if (l < n && r < m)
            {
                if (a[l] >= b[r])
                    l++;
                else
                    r++;
            }
            else if (l == n)
                r++;
            else if (r == m)
                l++;
            best_split[i] = { l, r };
        }
        while (q--)
        {
            int x, y, z;
            cin >> x >> y >> z;
            int l = best_split[z].first;
            int r = best_split[z].second;
            if (l > x)
                cout << prefix_a[x] + prefix_b[z - x] << endl;
            else if (r > y)
                cout << prefix_a[z - y] + prefix_b[y] << endl;
            else
                cout << prefix_a[l] + prefix_b[r] << endl;
        }
    }
    return 0;
}