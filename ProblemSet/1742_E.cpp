#include <iostream>
#include <vector>
using namespace std;

struct stair
{
    long long height;
    int max_step;

    stair() : height(0), max_step(0) {}
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<stair> a(n + 1);
        for (int i = 0; i < n; i++)
        {
            int diff;
            cin >> diff;
            a[i + 1].height = a[i].height + diff;
            a[i + 1].max_step = max(a[i].max_step, diff);
        }
        while (q--)
        {
            int k;
            cin >> k;
            int l = 0, r = n - 1;
            long long max_height = 0;
            while (l <= r)
            {
                int m = l + (r - l) / 2;
                if (a[m + 1].max_step <= k)
                {
                    max_height = a[m + 1].height;
                    l = m + 1;
                }
                else
                    r = m - 1;
            }
            cout << max_height << " ";
        }
        cout << endl;
    }
    return 0;
}