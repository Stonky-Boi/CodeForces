#include <iostream>
#include <vector>
using namespace std;

// The actually good solution
// #include <cmath>
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         long long c;
//         cin >> n >> c;
//         vector<int> s(n);
//         long double sum = 0, square_sum = 0;
//         for (int &i : s)
//         {
//             cin >> i;
//             sum += i;
//             square_sum += i * i;
//         }
//         long double d = sum * sum + n * (c - square_sum);
//         long double root = sqrtl(d);
//         long long w = (root - sum) / (2 * n);
//         cout << w << endl;
//     }
//     return 0;
// }

bool valid(vector<int> &s, long long c, int w)
{
    long long sum = 0;
    for (const int &i : s)
    {
        int side = i + 2 * w;
        sum += 1ll * side * side;
        if (sum > c)
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
        long long c;
        cin >> n >> c;
        vector<int> s(n);
        for (int &i : s)
            cin >> i;
        int l = 1, r = 1e9;
        int w;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (valid(s, c, m))
            {
                w = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        cout << w << endl;
    }
    return 0;
}