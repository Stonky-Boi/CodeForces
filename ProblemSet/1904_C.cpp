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
        vector<long long> a(n);
        for (long long &i : a)
            cin >> i;
        if (k >= 3)
        {
            cout << 0 << endl;
            continue;
        }
        sort(a.begin(), a.end());
        long long minimum = a[0];
        for (int i = 1; i < n; i++)
            minimum = min(minimum, a[i] - a[i - 1]);
        if (k == 2)
        {
            for (int i = 0; i < n; i++)
            {
                int p = i + 1;
                for (int j = i + 1; j < n; j++)
                {
                    long long value = a[j] - a[i];
                    while (p < n && a[p] < value)
                        p++;
                    if (p < n)
                        minimum = min(minimum, llabs(a[p] - value));
                    if (p > 0)
                        minimum = min(minimum, llabs(a[p - 1] - value));
                }
            }
        }
        cout << minimum << endl;
    }
    return 0;
}