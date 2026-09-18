#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    vector<long long> l(n, 0), r(n, 0);
    for (int i = 1; i < n; ++i)
    {
        l[i] = max(0LL, a[i] - a[i + 1]);
        r[i] = max(0LL, a[i + 1] - a[i]);
    }
    vector<long long> pl(n + 1, 0), pr(n + 1, 0);
    for (int i = 1; i < n; ++i)
    {
        pl[i] = pl[i - 1] + l[i];
        pr[i] = pr[i - 1] + r[i];
    }
    while (m--)
    {
        int s, t;
        cin >> s >> t;
        long long damage;
        if (s < t)
            damage = pl[t - 1] - pl[s - 1];
        else
            damage = pr[s - 1] - pr[t - 1];
        cout << damage << endl;
    }
    return 0;
}