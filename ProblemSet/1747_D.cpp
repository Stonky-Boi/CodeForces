#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> pref(n + 1, 0), zero(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] ^ a[i];
        zero[i] = zero[i - 1] + (a[i] == 0);
    }
    vector<int> values = pref;
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    int m = values.size();
    vector<int> index(n + 1);
    for (int i = 0; i <= n; i++)
        index[i] = lower_bound(values.begin(), values.end(), pref[i]) - values.begin();
    vector<vector<int>> last(2, vector<int>(m, -1));
    vector<int> next_match(n + 1, -1);
    for (int i = n; i >= 1; i--)
    {
        next_match[i] = last[i % 2][index[i - 1]];
        last[i % 2][index[i]] = i;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (pref[r] != pref[l - 1])
        {
            cout << -1 << endl;
            continue;
        }
        if (zero[r] - zero[l - 1] == r - l + 1)
        {
            cout << 0 << endl;
            continue;
        }
        if ((r - l + 1) % 2 == 1 || a[l] == 0 || a[r] == 0)
        {
            cout << 1 << endl;
            continue;
        }
        cout << (next_match[l] != -1 && next_match[l] < r ? 2 : -1) << endl;
    }
    return 0;
}