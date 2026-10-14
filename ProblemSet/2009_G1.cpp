#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(n);
        vector<int> freq(2 * n + 1, 0);
        vector<int> count(k + 1, 0);
        for (int &i : a)
            cin >> i;
        int max_value = 0;
        for (int i = 0; i < k; i++)
        {
            int x = a[i] - (i + 1) + n;
            count[freq[x]]--;
            freq[x]++;
            count[freq[x]]++;
            max_value = max(max_value, freq[x]);
        }
        vector<int> f(n - k + 1);
        f[0] = k - max_value;
        for (int i = k; i < n; i++)
        {
            int x = a[i - k] - (i - k + 1) + n;
            count[freq[x]]--;
            freq[x]--;
            count[freq[x]]++;
            int y = a[i] - (i + 1) + n;
            count[freq[y]]--;
            freq[y]++;
            count[freq[y]]++;
            while (max_value > 0 && count[max_value] == 0)
                max_value--;
            max_value = max(max_value, freq[y]);
            f[i - k + 1] = k - max_value;
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << f[l - 1] << endl;
        }
    }
    return 0;
}