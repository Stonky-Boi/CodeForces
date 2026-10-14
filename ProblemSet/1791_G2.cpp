#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point
{
    int cost;
    int first;
    int later;
    long long prefix;
    int rank;

    bool operator<(const point &other) const
    {
        return later < other.later;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<point> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].cost;
            a[i].first = a[i].cost + (i + 1);
            a[i].later = a[i].cost + min(i + 1, n - i);
        }
        sort(a.begin(), a.end());
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            a[i].rank = i;
            sum += a[i].later;
            a[i].prefix = sum;
        }
        int teleporters = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i].first > c)
                continue;
            int remaining = c - a[i].first;
            int l = 0, r = n - 1;
            int count = 0;
            while (l <= r)
            {
                int m = l + (r - l) / 2;
                long long cost = (m == 0 ? 0 : (m <= a[i].rank ? a[m - 1].prefix : a[m].prefix - a[i].later));
                if (cost <= remaining)
                {
                    count = m;
                    l = m + 1;
                }
                else
                    r = m - 1;
            }
            teleporters = max(teleporters, 1 + count);
        }
        cout << teleporters << endl;
    }
    return 0;
}