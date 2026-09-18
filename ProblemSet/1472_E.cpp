#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

struct my_min
{
    pair<int, int> mn1, mn2;
};

vector<pair<int, my_min>> create_min_prefix(const vector<tuple<int, int, int>> &a)
{
    vector<pair<int, my_min>> prefix_min;
    my_min curr_min{pair<int, int>(INT_MAX, -1), pair<int, int>(INT_MAX, -1)};
    for (auto &[h, w, id] : a)
    {
        if (w < curr_min.mn1.first)
        {
            curr_min.mn2 = curr_min.mn1;
            curr_min.mn1 = pair<int, int>(w, id);
        }
        else
            curr_min.mn2 = min(curr_min.mn2, pair<int, int>(w, id));
        prefix_min.emplace_back(h, curr_min);
    }
    return prefix_min;
}

int find_friend(const vector<pair<int, my_min>> &mins, int h, int w, int id)
{
    int l = -1, r = (int)mins.size();
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (mins[m].first < h)
            l = m;
        else
            r = m;
    }
    if (l == -1)
        return -1;
    pair<int, int> mn1 = mins[l].second.mn1;
    pair<int, int> mn2 = mins[l].second.mn2;
    if (mn1.second != id)
        return mn1.first < w ? mn1.second + 1 : -1;
    return mn2.first < w ? mn2.second + 1 : -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<tuple<int, int, int>> hor, ver;
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++)
        {
            int h, w;
            cin >> h >> w;
            hor.push_back({h, w, i});
            ver.push_back({w, h, i});
            a.push_back({h, w});
        }
        sort(hor.begin(), hor.end());
        sort(ver.begin(), ver.end());
        vector<pair<int, my_min>> hor_min = create_min_prefix(hor);
        vector<pair<int, my_min>> ver_min = create_min_prefix(ver);
        for (int i = 0; i < n; i++)
        {
            int h = a[i].first;
            int w = a[i].second;
            int id = find_friend(hor_min, h, w, i);
            if (id == -1)
                id = find_friend(ver_min, h, w, i);
            cout << id << " ";
        }
        cout << endl;
    }
    return 0;
}