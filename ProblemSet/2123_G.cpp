#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

// int mod(int a, int m)
// {
//     return (a % m + m) % m;
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         long int n, m, q;
//         cin >> n >> m >> q;
//         long int a[n + 2];
//         for (int i = 1; i <= n; i++)
//             cin >> a[i];
//         a[0] = 0;
//         map<int, long long> ans;
//         for (int i = 1; i * i <= m; i++)
//         {
//             if (m % i == 0)
//             {
//                 ans[i] = 0;
//                 if (i != m / i)
//                     ans[m / i] = 0;
//             }
//         }
//         for (auto p : ans)
//             for (int i = 1; i <= n; i++)
//                 ans[p.first] += mod(a[i] - a[i - 1], p.first);
//         while (q--)
//         {
//             int operation;
//             cin >> operation;
//             if (operation == 1)
//             {
//                 long int i, x;
//                 cin >> i >> x;
//                 for (auto &p : ans)
//                 {
//                     int g = p.first;
//                     p.second += mod(x - a[i - 1], g) - mod(a[i] - a[i - 1], g);
//                     if (i != n)
//                         p.second += mod(a[i + 1] - x, g) - mod(a[i + 1] - a[i], g);
//                 }
//                 a[i] = x;
//             }
//             else
//             {
//                 long int k;
//                 cin >> k;
//                 int g = __gcd(k, m);
//                 if (ans[g] < m)
//                     cout << "YES" << endl;
//                 else
//                     cout << "NO" << endl;
//             }
//         }
//     }
//     return 0;
// }

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n, m, q;
        cin >> n >> m >> q;
        long int a[n + 2];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        a[0] = 0;
        map<int, int> ans;
        for (int i = 1; i * i <= m; i++)
        {
            if (m % i == 0)
            {
                ans[i] = 0;
                if (i != m / i)
                    ans[m / i] = 0;
            }
        }
        for (auto p : ans)
        {
            int g = p.first;
            for (int i = 1; i <= n; i++)
                if (a[i] % g < a[i - 1] % g)
                    ans[g]++;
        }
        while (q--)
        {
            int operation;
            cin >> operation;
            if (operation == 1)
            {
                long int i, x;
                cin >> i >> x;
                for (auto &p : ans)
                {
                    int g = p.first;
                    p.second += (x % g < a[i - 1] % g) - (a[i] % g < a[i - 1] % g);
                    if (i != n)
                        p.second += (a[i + 1] % g < x % g) - (a[i + 1] % g < a[i] % g);
                }
                a[i] = x;
            }
            else
            {
                long int k;
                cin >> k;
                int g = __gcd(k, m);
                if (ans[g] < m / g)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
    }
    return 0;
}