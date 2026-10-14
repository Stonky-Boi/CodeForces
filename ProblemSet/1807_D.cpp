#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        vector<int> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            prefix_sum[i + 1] = prefix_sum[i] + a[i];
        }
        while (q--)
        {
            int l, r, k;
            cin >> l >> r >> k;
            int sum = prefix_sum[n] - prefix_sum[r] + prefix_sum[l - 1];
            sum += k * (r - l + 1);
            cout << (sum % 2 == 0 ? "NO" : "YES") << endl;
        }
    }
    return 0;
}