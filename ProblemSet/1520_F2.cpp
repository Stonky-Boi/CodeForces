#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> cache(n + 1, -1);
    while (t--)
    {
        int k;
        cin >> k;
        int l = 1, r = n;
        while (l < r)
        {
            int m = (l + r) / 2;
            int ones;
            if (cache[m] != -1)
                ones = cache[m];
            else
            {
                cout << "? " << 1 << " " << m << endl;
                cin >> cache[m];
                ones = cache[m];
            }
            int zeros = m - ones;
            if (zeros >= k)
                r = m;
            else
                l = m + 1;
        }
        cout << "! " << l << endl;
        for (int i = l; i <= n; i++)
            if (cache[i] != -1)
                cache[i] += 1;
    }
    return 0;
}