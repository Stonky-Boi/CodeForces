#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (long long &i : a)
            cin >> i;
        vector<long long> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix_sum[i + 1] = prefix_sum[i] + a[i];
        vector<bool> exact(n + 1, false);
        exact[0] = true;
        exact[n] = true;
        bool possible = false;
        for (int i = 1; i < n; i++)
        {
            long long l = prefix_sum[i] * (n - i), r = (prefix_sum[n] - prefix_sum[i]) * i;
            if (l < r)
            {
                cout << "YES" << endl;
                possible = true;
                break;
            }
            if (l == r)
                exact[i] = true;
        }
        if (possible)
            continue;
        for (int i = 0; i < n; i++)
        {
            if (!exact[i] && !exact[i + 1])
            {
                cout << "NO" << endl;
                possible = true;
                break;
            }
        }
        if (!possible)
            cout << "YES" << endl;
    }
    return 0;
}