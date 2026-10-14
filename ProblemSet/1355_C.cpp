#include <iostream>
using namespace std;

// #include <vector>
// int main()
// {
//     int a, b, c, d;
//     cin >> a >> b >> c >> d;
//     int limit = max(2 * c, d);
//     vector<long long> diff(limit + 2, 0);
//     vector<long long> count(limit + 2, 0);
//     vector<long long> prefix(limit + 2, 0);
//     for (int i = a; i <= b; i++)
//     {
//         diff[i + b]++;
//         diff[i + c + 1]--;
//     }
//     for (int i = 1; i <= limit; i++)
//         count[i] = count[i - 1] + diff[i];
//     for (int i = 1; i <= limit; i++)
//         prefix[i] = prefix[i - 1] + count[i];
//     long long total = 1ll * (b - a + 1) * (c - b + 1);
//     long long triangles = 0;
//     for (int i = c; i <= d; i++)
//         triangles += total - prefix[i];
//     cout << triangles << endl;
//     return 0;
// }

int main()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long triangles = 0;
    for (long long i = b; i <= c; i++)
    {
        long long l = max(a, c - i);
        long long r = min(b, d - i);
        if (l <= r)
        {
            long long count = r - l + 1;
            triangles += count * (i - c);
            triangles += (r * (r + 1) / 2 - l * (l - 1) / 2);
        }
        l = max(a, d - i + 1);
        r = b;
        if (l <= r)
            triangles += (r - l + 1) * (d - c + 1);
    }
    cout << triangles << endl;
    return 0;
}