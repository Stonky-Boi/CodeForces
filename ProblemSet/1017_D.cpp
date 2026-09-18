#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> w(n);
    for (auto &i : w)
        cin >> i;
    int mask_limit = 1 << n;
    vector<long long> count(mask_limit, 0);
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        int mask = 0;
        for (int j = 0; j < n; j++)
            if (s[j] == '1')
                mask |= (1 << j);
        count[mask]++;
    }
    vector<int> wu_value(mask_limit, 0);
    for (int i = 0; i < mask_limit; i++)
    {
        int val = 0;
        for (int j = 0; j < n; j++)
            if (((i >> j) & 1) == 0)
                val += w[j];
        wu_value[i] = val;
    }
    const int MAX_W = 1200;
    vector<vector<long long>> freq(mask_limit, vector<long long>(MAX_W + 1, 0));
    for (int t_mask = 0; t_mask < mask_limit; t_mask++)
    {
        for (int s_mask = 0; s_mask < mask_limit; s_mask++)
        {
            int wu = wu_value[s_mask ^ t_mask];
            if (wu <= MAX_W)
                freq[t_mask][wu] += count[s_mask];
        }
        for (int k = 1; k <= MAX_W; k++)
            freq[t_mask][k] += freq[t_mask][k - 1];
    }
    while (q--)
    {
        string t;
        int k;
        cin >> t >> k;
        int t_mask = 0;
        for (int i = 0; i < n; i++)
            if (t[i] == '1')
                t_mask |= (1 << i);
        if (k > MAX_W)
            k = MAX_W;
        cout << freq[t_mask][k] << " ";
    }
    cout << endl;
    return 0;
}