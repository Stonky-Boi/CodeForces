#include <iostream>
using namespace std;

// // My initial solution
// int main()
// {
//     int n;
//     cin >> n;
//     long long k;
//     cin >> k;
//     long long powers[n];
//     powers[0] = 1;
//     for (int i = 1; i < n; i++)
//         powers[i] = powers[i - 1] * 2;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         if (k % powers[i] == 0)
//         {
//             cout << i + 1 << endl;
//             break;
//         }
//     }
//     return 0;
// }

int main()
{
    long long n, k;
    cin >> n >> k;
    int trailing_zeros = 0;
    while ((k & 1) == 0)
    {
        k >>= 1;
        trailing_zeros++;
    }
    cout << trailing_zeros + 1 << endl;
    return 0;
}