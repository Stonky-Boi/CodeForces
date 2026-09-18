#include <iostream>
#include <algorithm>
using namespace std;

// // my solution
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, k;
//         cin >> n >> k;
//         pair<long long int, int> h[n];
//         for (int i = 0; i < n; i++)
//         {
//             cin >> h[i].first;
//             h[i].second = i;
//         }
//         long long int start_height = h[k - 1].first;
//         sort(h, h + n);
//         int position = -1;
//         for (int i = 0; i < n; i++)
//         {
//             if (h[i].second == k - 1)
//             {
//                 position = i;
//                 break;
//             }
//         }
//         long long int current_height = start_height;
//         long long int max_height = h[n - 1].first;
//         long long int time = 0;
//         if (current_height == max_height)
//         {
//             cout << "YES" << endl;
//             continue;
//         }
//         for (int i = position + 1; i < n; i++)
//         {
//             long long int next_height = h[i].first;
//             long long int teleport_time = abs(current_height - next_height);
//             if (time + teleport_time <= current_height)
//             {
//                 time += teleport_time;
//                 current_height = next_height;
//             }
//             else
//                 break;
//         }
//         cout << (current_height == max_height ? "YES" : "NO") << endl;
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
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int current = a[k - 1];
        int distance = a[k - 1];
        sort(a, a + n);
        bool possible = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < current)
                continue;
            if (a[i] - current > distance)
                possible = false;
            current = a[i];
        }
        if (possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}