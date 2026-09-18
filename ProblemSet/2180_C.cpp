#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        int k;
        cin >> n >> k;
        vector<long long> a(k, 0);
        if (k & 1)
            for (auto &i : a)
                i = n;
        else
        {
            int excluded = 0;
            for (int i = 30; i >= 0; i--)
            {
                if (n >> i & 1)
                {
                    for (int j = 0; j < k; j++)
                        if (j != min(excluded, k - 1))
                            a[j] += (1 << i);
                    if (excluded < k)
                        excluded++;
                }
                else
                    for (int j = 0; j < excluded / 2 * 2; j++)
                        a[j] += (1 << i);
            }
        }
        for (int i = 0; i < k; i++)
            cout << a[i] << (i == k - 1 ? "\n" : " ");
    }
    return 0;
}