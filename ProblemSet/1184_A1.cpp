#include <iostream>
using namespace std;

// // Initial attempt
// int main()
// {
//     long long r;
//     cin >> r;
//     long long x = 1;
//     for (int i = 0; i < 10e6; i++)
//     {
//         long long y = r - x * x - x - 1;
//         if (y > 0 && y % (2 * x) == 0)
//         {
//             y = y / (2 * x);
//             cout << x << " " << y << endl;
//             return 0;
//         }
//         x++;
//     }
//     cout << "NO" << endl;
//     return 0;
// }

int main()
{
    long long r;
    cin >> r;
    if (r % 2 == 0 || r <= 3)
        cout << "NO" << endl;
    else
        cout << 1 << " " << (r - 3) / 2 << endl;
    return 0;
}