#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> a;

pair<int, int> check(long long x)
{
    int total_masks = 1 << m;
    vector<int> index(total_masks, -1);
    for (int i = 0; i < n; i++)
    {
        int mask = 0;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] >= x)
                mask |= (1 << j);
        }
        index[mask] = i;
    }
    int full = (1 << m) - 1;
    for (int mask1 = 0; mask1 < total_masks; mask1++)
    {
        if (index[mask1] == -1)
            continue;
        for (int mask2 = 0; mask2 < total_masks; mask2++)
        {
            if (index[mask2] == -1)
                continue;
            if ((mask1 | mask2) == full)
                return {index[mask1], index[mask2]};
        }
    }
    return {-1, -1};
}

int main()
{
    cin >> n >> m;
    a.resize(n, vector<int>(m));
    long long l = 0;
    long long r = 1000000000ll;
    for (vector<int> &v : a)
        for (int &i : v)
            cin >> i;
    int first, second;
    while (l <= r)
    {
        long long m = (l + r) / 2;
        auto [i, j] = check(m);
        if (i != -1)
        {
            l = m + 1;
            first = i;
            second = j;
        }
        else
            r = m - 1;
    }
    cout << first + 1 << ' ' << second + 1 << endl;
    return 0;
}