#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a;
        cin >> b;
        int pre_a[n + 1], pre_b[n + 1];
        pre_a[0] = 0, pre_b[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            pre_a[i] = pre_a[i - 1] + (a[i - 1] == '0' ? 1 : -1);
            pre_b[i] = pre_b[i - 1] + (b[i - 1] == '1' ? 1 : -1);
        }
        sort(pre_a + 1, pre_a + n + 1);
        sort(pre_b + 1, pre_b + n + 1);
        long long int pre_b_sum[n + 1];
        pre_b_sum[0] = 0;
        for (int i = 1; i <= n; i++)
            pre_b_sum[i] = pre_b_sum[i - 1] + pre_b[i];
        long long int total_diff = 0;
        int j = 0;
        for (int i = 1; i <= n; i++)
        {
            while (j < n && pre_b[j + 1] < pre_a[i])
                j++;
            long long int less_sum = (long long int)pre_a[i] * j - pre_b_sum[j];
            long long int more_sum = (pre_b_sum[n] - pre_b_sum[j]) - (long long int)pre_a[i] * (n - j);
            total_diff += less_sum + more_sum;
        }
        long long int sum = (long long int)n * n * (n + 1) / 2 - total_diff / 2;
        cout << sum << endl;
    }
    return 0;
}