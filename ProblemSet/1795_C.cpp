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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int &i : a)
            cin >> i;
        for (int &i : b)
            cin >> i;
        vector<long long> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix_sum[i + 1] = prefix_sum[i] + b[i];
        vector<long long> difference(n + 1, 0);
        vector<long long> add(n, 0);
        for (int i = 0; i < n; i++)
        {
            long long target = prefix_sum[i] + a[i];
            int j = upper_bound(prefix_sum.begin() + i, prefix_sum.end(), target) - prefix_sum.begin() - 1;
            difference[i]++;
            difference[j]--;
            if (j < n)
            {
                long long used = prefix_sum[j] - prefix_sum[i];
                add[j] += a[i] - used;
            }
        }
        long long curr = 0;
        for (int i = 0; i < n; i++)
        {
            curr += difference[i];
            long long tea = curr * b[i] + add[i];
            cout << tea << " ";
        }
        cout << endl;
    }
    return 0;
}