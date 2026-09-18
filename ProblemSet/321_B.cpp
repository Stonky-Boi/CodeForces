#include <iostream>
#include <algorithm>
using namespace std;

bool compare_jiro(const pair<bool, int> &a, const pair<bool, int> &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main()
{
    int n, m;
    cin >> n >> m;
    pair<bool, int> jiro[n];
    int ciel[m];
    for (auto &[type, val] : jiro)
    {
        string pos;
        cin >> pos >> val;
        type = (pos == "ATK");
    }
    for (auto &x : ciel)
        cin >> x;
    int approach1 = 0, approach2 = 0;
    // only attack ATK cards
    sort(jiro, jiro + n, compare_jiro);
    sort(ciel, ciel + m, greater<int>());
    for (int i = 0; i < min(n, m); i++)
    {
        if (!jiro[i].first || ciel[i] <= jiro[i].second)
            break;
        approach1 += ciel[i] - jiro[i].second;
    }
    // try to kill all
    reverse(jiro, jiro + n);
    reverse(ciel, ciel + m);
    bool fail = false, used[m];
    for (auto &x : used)
        x = false;
    for (int i = 0; i < n; ++i)
    {
        bool matched = false;
        for (int j = 0; j < m; ++j)
        {
            if (used[j])
                continue;
            if ((jiro[i].first && ciel[j] >= jiro[i].second) || (!jiro[i].first && ciel[j] > jiro[i].second))
            {
                used[j] = true;
                if (jiro[i].first)
                    approach2 += ciel[j] - jiro[i].second;
                matched = true;
                break;
            }
        }
        if (!matched)
        {
            fail = true;
            break;
        }
    }
    if (fail)
    {
        cout << approach1 << endl;
        return 0;
    }
    for (int i = 0; i < m; ++i)
        if (!used[i])
            approach2 += ciel[i];
    cout << max(approach1, approach2) << endl;
    return 0;
}