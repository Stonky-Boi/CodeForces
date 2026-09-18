#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<long long> a(n), b(m);
        for (auto &i : a)
            cin >> i;
        for (auto &i : b)
            cin >> i;
        if (n < 2 * m)
        {
            cout << "NO" << endl;
            continue;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool possible = true;
        for (int i = 0; i < m; i++)
        {
            if (a[i] >= b[i] || a[n - m + i] <= b[i])
            {
                possible = false;
                break;
            }
        }
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}