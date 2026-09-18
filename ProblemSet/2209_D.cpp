#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long r, g, b;
        cin >> r >> g >> b;
        vector<pair<int, char>> v = {{r, 'R'}, {g, 'G'}, {b, 'B'}};
        sort(v.begin(), v.end(), greater<pair<int, char>>());
        v[0].first = min(v[0].first, v[1].first + v[2].first + 1);
        int n = v[0].first + v[1].first + v[2].first;
        if (n == 0)
        {
            cout << endl;
            continue;
        }
        string weapon(n, ' ');
        int target = (n + 1) / 2;
        int mask = -1;
        for (int i = 1; i < 8; i++)
        {
            int sum = 0;
            if (i & 1)
                sum += v[0].first;
            if (i & 2)
                sum += v[1].first;
            if (i & 4)
                sum += v[2].first;
            if (sum == target)
            {
                mask = i;
                break;
            }
        }
        if (mask != -1)
        {
            int evens = 0, odds = 1;
            for (int i = 0; i < 3; i++)
            {
                int count = v[i].first;
                while (count--)
                {
                    if (mask & (1 << i))
                    {
                        weapon[evens] = v[i].second;
                        evens += 2;
                    }
                    else
                    {
                        weapon[odds] = v[i].second;
                        odds += 2;
                    }
                }
            }
        }
        else
        {
            vector<int> order;
            for (int i = n - 1; i >= 0; i--)
                if (i % 2 == 0)
                    order.push_back(i);
            for (int i = n - 1; i >= 0; i--)
                if (i % 2 != 0)
                    order.push_back(i);
            int pointer = 0;
            for (int i = 0; i < 3; i++)
            {
                int count = v[i].first;
                while (count--)
                    weapon[order[pointer++]] = v[i].second;
            }
        }
        cout << weapon << endl;
    }
    return 0;
}