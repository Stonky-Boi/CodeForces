#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> activity(int n)
{
    vector<int> friends(n);
    int max1 = 0, max2 = 0, max3 = 0;
    int day1 = -1, day2 = -1, day3 = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> friends[i];
        if (friends[i] >= max1)
        {
            max3 = max2;
            day3 = day2;
            max2 = max1;
            day2 = day1;
            max1 = friends[i];
            day1 = i;
        }
        else if (friends[i] >= max2)
        {
            max3 = max2;
            day3 = day2;
            max2 = friends[i];
            day2 = i;
        }
        else if (friends[i] >= max3)
        {
            max3 = friends[i];
            day3 = i;
        }
    }
    return {{max1, day1}, {max2, day2}, {max3, day3}};
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int max_friends = 0;
        vector<pair<int, int>> a = activity(n);
        vector<pair<int, int>> b = activity(n);
        vector<pair<int, int>> c = activity(n);
        for (const auto &[m1, d1] : a)
        {
            for (const auto &[m2, d2] : b)
            {
                for (const auto &[m3, d3] : c)
                {
                    if (d1 != d2 && d1 != d3 && d2 != d3)
                        max_friends = max(max_friends, m1 + m2 + m3);
                }
            }
        }
        cout << max_friends << endl;
    }
    return 0;
}