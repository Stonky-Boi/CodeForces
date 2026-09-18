#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, pair<int, int>> position;
    for (int i = 0; i < n; i++)
    {
        if (position.find(a[i]) == position.end())
            position[a[i]] = {i, i};
        else
            position[a[i]].second = i;
    }
    vector<pair<int, int>> segments;
    for (auto &p : position)
        segments.push_back(p.second);
    sort(segments.begin(), segments.end());
    int difficulty = 0;
    int i = 0;
    while (i < segments.size())
    {
        int l = segments[i].first;
        int r = segments[i].second;
        int j = i + 1;
        while (j < segments.size() && segments[j].first <= r)
        {
            r = max(r, segments[j].second);
            ++j;
        }
        map<int, int> frequency;
        for (int k = l; k <= r; ++k)
            frequency[a[k]]++;
        int max_freq = 0;
        for (auto &f : frequency)
            max_freq = max(max_freq, f.second);
        difficulty += (r - l + 1 - max_freq);
        i = j;
    }
    cout << difficulty << endl;
    return 0;
}