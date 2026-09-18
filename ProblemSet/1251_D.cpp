#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct employee
{
    long long l, r;
};

bool possible(long long x, const vector<employee> &a, long long s, long long sum)
{
    int n = a.size();
    int need = (n + 1) / 2;
    int base = 0;
    vector<long long> costs;
    for (auto [l, r] : a)
    {
        if (l >= x)
            base++;
        else if (r >= x)
            costs.push_back(x - l);
    }
    need -= base;
    if (need <= 0)
        return true;
    if (costs.size() < need)
        return false;
    nth_element(costs.begin(), costs.begin() + need, costs.end());
    long long extra = 0;
    for (int i = 0; i < need; i++)
    {
        extra += costs[i];
        if (sum + extra > s)
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long s;
        cin >> n >> s;
        vector<employee> a(n);
        long long sum = 0;
        for (auto &[l, r] : a)
        {
            cin >> l >> r;
            sum += l;
        }
        long long l = 1;
        long long r = 1000000000;
        long long median = 1;
        while (l <= r)
        {
            long long m = l + (r - l) / 2;
            if (possible(m, a, s, sum))
            {
                median = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        cout << median << endl;
    }
    return 0;
}