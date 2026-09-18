#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<long long> x(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    int m = n - k + 1;
    vector<long long> window_sum(m + 1);
    long long current = 0;
    for (int i = 1; i <= n; i++)
    {
        current += x[i];
        if (i > k)
            current -= x[i - k];
        if (i >= k)
            window_sum[i - k + 1] = current;
    }
    vector<int> best_left(m + 1);
    best_left[1] = 1;
    for (int i = 2; i <= m; i++)
    {
        if (window_sum[i] > window_sum[best_left[i - 1]])
            best_left[i] = i;
        else
            best_left[i] = best_left[i - 1];
    }
    vector<int> best_right(m + 2);
    best_right[m] = m;
    for (int i = m - 1; i >= 1; i--)
    {
        if (window_sum[i] >= window_sum[best_right[i + 1]])
            best_right[i] = i;
        else
            best_right[i] = best_right[i + 1];
    }
    long long best_total = -1;
    int max1 = 1, max2 = k + 1;
    for (int i = 1; i + k <= m; i++)
    {
        int j = best_right[i + k];
        long long total = window_sum[i] + window_sum[j];
        if (total > best_total || (total == best_total && (i < max1 || (i == max1 && j < max2))))
        {
            best_total = total;
            max1 = i;
            max2 = j;
        }
    }
    cout << max1 << " " << max2 << endl;
    return 0;
}