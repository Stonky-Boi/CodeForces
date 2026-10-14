#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct building
{
    int index;
    int visits;
    int coordinate;

    bool operator<(const building &other) const
    {
        return index < other.index;
    }

    bool operator>(const building &other) const
    {
        return visits > other.visits;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<building> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i].index = i;
            cin >> a[i].visits;
        }
        sort(a.begin(), a.end(), greater<building>());
        long long time = 0;
        for (int i = 0; i < n; i++)
        {
            int position = i / 2 + 1;
            if (i % 2 == 0)
                a[i].coordinate = position;
            else
                a[i].coordinate = -position;
            time += 2ll * a[i].visits * position;
        }
        sort(a.begin(), a.end());
        cout << time << endl;
        cout << 0 << " ";
        for (const auto &[_, __, c] : a)
            cout << c << " ";
        cout << endl;
    }
    return 0;
}