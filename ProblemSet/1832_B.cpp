#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        sort(a.begin(), a.end());
        vector<long long> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix_sum[i + 1] = prefix_sum[i] + a[i];
        long long sum = 0;
        for (int i = 0; i <= k; i++)
        {
            int l = 2 * i, r = n - (k - i);
            sum = max(sum, prefix_sum[r] - prefix_sum[l]);
        }
        cout << sum << endl;
    }
    return 0;
}