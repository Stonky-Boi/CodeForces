#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> x(n + 1);
        x[0] = 0;
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        vector<long long> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix_sum[i + 1] = prefix_sum[i] + x[i + 1];
        long long min_cost = numeric_limits<long long>::max();
        for (int i = 0; i <= n; i++)
        {
            long long cost = 1ll * a * x[i] + 1ll * b * (prefix_sum[n] - prefix_sum[i] - 1ll * (n - i - 1) * x[i]);
            min_cost = min(min_cost, cost);
        }
        cout << min_cost << endl;
    }
    return 0;
}