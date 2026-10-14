#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int MOD = 1e9 + 7;
    int MAXN = 2e5;
    vector<long long> inverse(MAXN + 1, 1);
    for (int i = 2; i <= MAXN; i++)
        inverse[i] = MOD - (MOD / i) * inverse[MOD % i] % MOD;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        sort(a.begin(), a.end());
        vector<int> unique, freq;
        for (int i = 0; i < n; i++)
        {
            if (unique.empty() || unique.back() != a[i])
            {
                unique.push_back(a[i]);
                freq.push_back(1);
            }
            else
                freq.back()++;
        }
        int k = unique.size();
        vector<long long> prefix_freq(k + 1, 1);
        for (int i = 0; i < k; i++)
            prefix_freq[i + 1] = prefix_freq[i] * freq[i] % MOD;
        vector<long long> prefix_inverse(k + 1, 1);
        for (int i = 0; i < k; i++)
            prefix_inverse[i + 1] = prefix_inverse[i] * inverse[freq[i]] % MOD;
        long long dances = 0;
        for (int i = 0; i + m <= k; i++)
        {
            if (unique[i + m - 1] - unique[i] == m - 1)
            {
                long long ways = prefix_freq[i + m] * prefix_inverse[i] % MOD;
                dances = (dances + ways) % MOD;
            }
        }
        cout << dances << endl;
    }
    return 0;
}