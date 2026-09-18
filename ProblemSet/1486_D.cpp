#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n], prefix_sum[n];
    for (auto &x : a)
        cin >> x;
    int l = 1, r = n + 1;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        for (int i = 0; i < n; i++)
            prefix_sum[i] = (a[i] >= m ? 1 : -1);
        for (int i = 1; i < n; i++)
            prefix_sum[i] += prefix_sum[i - 1];
        int max_subarray = prefix_sum[k - 1];
        int min_prefix = 0;
        for (int i = k; i < n; i++)
        {
            min_prefix = min(min_prefix, prefix_sum[i - k]);
            max_subarray = max(max_subarray, prefix_sum[i] - min_prefix);
        }
        if (max_subarray > 0)
            l = m;
        else
            r = m;
    }
    cout << l << endl;
    return 0;
}