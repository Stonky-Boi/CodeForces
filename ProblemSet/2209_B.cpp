#include <iostream>
using namespace std;

// // My contest logic
// #include <vector>
// #include <algorithm>

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         long long a[n];
//         for (auto &i : a)
//             cin >> i;
//         vector<int> max_indices(n);
//         for (int i = 0; i < n; i++)
//         {
//             vector<pair<long long, int>> critical_points;
//             for (int j = i + 1; j < n; j++)
//             {
//                 long long m = a[i] + a[j];
//                 if (a[j] > a[i])
//                     critical_points.push_back({m, +1});
//                 else if (a[j] < a[i])
//                     critical_points.push_back({m, -1});
//             }
//             sort(critical_points.begin(), critical_points.end());
//             int curr = 0;
//             for (auto p : critical_points)
//                 if (p.second == -1)
//                     curr++;
//             int best = curr;
//             for (auto p : critical_points)
//             {
//                 if (p.second == -1)
//                     curr--;
//                 else
//                     curr++;
//                 if (curr > best)
//                     best = curr;
//             }
//             max_indices[i] = best;
//         }
//         for (auto i : max_indices)
//             cout << i << " ";
//         cout << endl;
//     }
//     return 0;
// }

// Editorial logic
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long a[n];
        for (auto &i : a)
            cin >> i;
        for (int i = 0; i < n; i++)
        {
            int smaller = 0, larger = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] > a[j])
                    smaller++;
                else if (a[i] < a[j])
                    larger++;
            }
            cout << max(smaller, larger) << " ";
        }
        cout << endl;
    }
    return 0;
}