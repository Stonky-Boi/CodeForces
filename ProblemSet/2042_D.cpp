#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct segment
{
    int l, r;
    int index;

    bool operator<(const segment &other) const
    {
        if (l == other.l)
            return r > other.r;
        return l < other.l;
    }
};

void update(vector<segment> &s, vector<int> &tracks, vector<bool> &duplicate)
{
    set<int> st;
    for (const auto &[l, r, i] : s)
    {
        if (!duplicate[i])
        {
            auto it = st.lower_bound(r);
            if (it != st.end())
                tracks[i] += *it - r;
        }
        st.insert(r);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<segment> s(n);
        vector<int> tracks(n, 0);
        vector<bool> duplicate(n, false);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i].l >> s[i].r;
            s[i].index = i;
        }
        sort(s.begin(), s.end());
        for (int i = 1; i < n; i++)
        {
            if (s[i].l == s[i - 1].l && s[i].r == s[i - 1].r)
            {
                duplicate[s[i].index] = true;
                duplicate[s[i - 1].index] = true;
            }
        }
        update(s, tracks, duplicate);
        for (auto &[l, r, i] : s)
        {
            int temp = l;
            l = -r;
            r = -temp;
        }
        sort(s.begin(), s.end());
        update(s, tracks, duplicate);
        for (const int &i : tracks)
            cout << i << endl;
    }
    return 0;
}