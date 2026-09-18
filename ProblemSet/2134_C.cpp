#include <iostream>
using namespace std;

// // my solution
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         long n;
//         cin >> n;
//         long long a[n];
//         for (int i = 0; i < n; i++)
//             cin >> a[i];
//         long long operations = 0;
//         for (int i = 1; i < n; i += 2)
//         {
//             long long left = a[i - 1];
//             long long right = (i + 1 < n ? a[i + 1] : 0);
//             long long excess = left + right - a[i];
//             if (excess > 0)
//             {
//                 if (i + 1 < n)
//                 {
//                     long long reduce_right = min(a[i + 1], excess);
//                     a[i + 1] -= reduce_right;
//                     operations += reduce_right;
//                     excess -= reduce_right;
//                 }
//                 if (excess > 0)
//                     operations += excess;
//             }
//         }
//         cout << operations << endl;
//     }
//     return 0;
// }

// editorial solution
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long n;
        cin >> n;
        long long a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long operations = 0;
        for (int i = 0; i < n; i += 2)
        {
            long long max_value = a[i];
            if (i >= 2)
                max_value = min(max_value, a[i - 1] - b[i - 2]);
            if (i + 1 < n)
                max_value = min(max_value, a[i + 1]);
            b[i] = max_value;
            operations += a[i] - b[i];
        }
        cout << operations << endl;
    }
    return 0;
}