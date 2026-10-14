#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 4e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        vector<long long> cold(k + 1), hot(k + 1);
        for (int i = 1; i <= k; i++)
            cin >> cold[i];
        for (int i = 1; i <= k; i++)
            cin >> hot[i];
        vector<long long> value(k + 1, INF);
        value[0] = 0;
        int min1 = 0, min2 = 1;
        long long lazy = 0;
        int prev = 0;
        for (int i = 0; i < n; i++)
        {
            int x = a[i];
            int y = prev;
            long long min_except = value[min1 != x ? min1 : min2] + lazy;
            long long prev_x = value[x] + lazy;
            long long cost = (x == y ? hot[x] : cold[x]);
            lazy += cost;
            long long candidate = INF;
            if (min_except < INF / 2)
                candidate = min_except + cold[x];
            if (x != y && prev_x < INF / 2)
                candidate = min(candidate, prev_x + hot[x]);
            if (candidate < INF / 2)
                candidate -= lazy;
            if (candidate < value[y])
            {
                value[y] = candidate;
                if (y == min2)
                {
                    if (value[min2] < value[min1])
                        swap(min1, min2);
                }
                else
                {
                    if (value[y] < value[min1])
                    {
                        min2 = min1;
                        min1 = y;
                    }
                    else if (value[y] < value[min2])
                        min2 = y;
                }
            }
            prev = x;
        }
        cout << value[min1] + lazy << endl;
    }
    return 0;
}