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
        long long k;
        cin >> n >> k;
        vector<long long> a(n);
        for (long long &i : a)
            cin >> i;
        long long left = *max_element(a.begin(), a.end());
        long long right = left + k;
        long long maximum = left;
        while (left <= right)
        {
            long long mid = (left + right) / 2;
            bool possible = false;
            for (int i = 0; i < n; i++)
            {
                long long need = mid;
                long long cost = 0;
                for (int j = i; j < n; j++)
                {
                    if (need <= a[j])
                        break;
                    if (j == n - 1)
                    {
                        cost = k + 1;
                        break;
                    }
                    cost += (need - a[j]);
                    if (cost > k)
                        break;
                    need--;
                }
                if (cost <= k)
                {
                    possible = true;
                    break;
                }
            }
            if (possible)
            {
                maximum = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        cout << maximum << endl;
    }
    return 0;
}