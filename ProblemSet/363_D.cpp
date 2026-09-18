#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    long long a;
    cin >> n >> m >> a;
    vector<long long> b(n), p(m);
    for (auto &x : b)
        cin >> x;
    for (auto &x : p)
        cin >> x;
    sort(b.begin(), b.end());
    sort(p.begin(), p.end());
    int l = 0, r = min(n, m), best = 0;
    long long best_shared = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        long long shared_needed = 0;
        for (int i = 0; i < m; i++)
        {
            long long boy = b[n - m + i];
            long long bike = p[i];
            if (bike > boy)
                shared_needed += bike - boy;
        }
        if (shared_needed <= a)
        {
            best = m;
            best_shared = shared_needed;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    long long total_cost = 0;
    for (int i = 0; i < best; i++)
        total_cost += p[i];
    long long personal_spent = max(0LL, total_cost - a);
    cout << best << " " << personal_spent << endl;
    return 0;
}