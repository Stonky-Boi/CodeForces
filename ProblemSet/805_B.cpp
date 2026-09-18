#include <iostream>
using namespace std;

// // My initial solution
// int main()
// {
//     int n;
//     cin >> n;
//     while (n > 4)
//     {
//         cout << "aabb";
//         n -= 4;
//     }
//     switch (n)
//     {
//     case 1:
//         cout << "a";
//         break;
//     case 2:
//         cout << "aa";
//         break;
//     case 3:
//         cout << "aab";
//         break;
//     case 4:
//         cout << "aabb";
//         break;
//     default:
//         break;
//     }
//     cout << endl;
//     return 0;
// }

int main()
{
    int n;
    cin >> n;
    string result;
    result.reserve(n);
    for (int i = 0; i < n; i++)
    {
        if ((i / 2) % 2 == 0)
            result.push_back('a');
        else
            result.push_back('b');
    }
    cout << result << endl;
    return 0;
}