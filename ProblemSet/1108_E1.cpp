#include <iostream>
#include <vector>
using namespace std;

struct segment
{
    int l, r;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector<segment> segments(m);
    for (auto &[l, r] : segments)
    {
        cin >> l >> r;
        --l;
        --r;
    }
    int best = 0;
    int maximum = 0;
    int minimum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            int curr = a[i] - a[j];
            for (int k = 0; k < m; k++)
            {
                bool covers_i = segments[k].l <= i && i <= segments[k].r;
                bool covers_j = segments[k].l <= j && j <= segments[k].r;
                if (covers_j && !covers_i)
                    curr++;
            }
            if (curr > best)
            {
                best = curr;
                maximum = i;
                minimum = j;
            }
        }
    }
    vector<int> answer;
    for (int k = 0; k < m; k++)
    {
        bool covers_max = segments[k].l <= maximum && maximum <= segments[k].r;
        bool covers_min = segments[k].l <= minimum && minimum <= segments[k].r;
        if (covers_min && !covers_max)
            answer.push_back(k + 1);
    }
    cout << best << endl;
    cout << answer.size() << endl;
    for (int i : answer)
        cout << i << ' ';
    cout << endl;
    return 0;
}