#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long get(long long x, long long n, long long d, long long sn, vector<long long> &p, vector<long long> &prefix)
{
    if (x <= 0)
        return 0;
    long long cycles = x / n;
    long long remaining = x % n;
    int i = upper_bound(p.begin(), p.end(), remaining) - p.begin();
    return cycles * sn + remaining * d + prefix[i];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, d;
        int m;
        cin >> n >> m >> d;
        vector<long long> p(m), r(m);
        vector<long long> prefix(m + 1, 0);
        for (int i = 0; i < m; i++)
        {
            cin >> p[i] >> r[i];
            prefix[i + 1] = prefix[i] + r[i];
        }
        long long sn = n * d + prefix[m];
        bool possible = false;
        for (int i = 0; i < m && !possible; i++)
        {
            for (int j = 0; j < m; j++)
            {
                long long x = p[i];
                long long y = p[j];
                long long left = get(x, n, d, sn, p, prefix);
                long long right = get(y, n, d, sn, p, prefix);
                long long whole = get(x + y + 1, n, d, sn, p, prefix);
                if (left + right > whole)
                {
                    possible = true;
                    break;
                }
            }
        }
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}