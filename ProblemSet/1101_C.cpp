#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct segment
{
    int l, r;
    int index;
    int group = 2;

    static bool comp_l(const segment &a, const segment &b)
    {
        return a.l < b.l;
    }

    static bool comp_index(const segment &a, const segment &b)
    {
        return a.index < b.index;
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
        vector<segment> s(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i].l >> s[i].r;
            s[i].index = i;
        }
        sort(s.begin(), s.end(), segment::comp_l);
        int max_right = s[0].r;
        int split = -1;
        for (int i = 1; i < n; i++)
        {
            if (s[i].l > max_right)
            {
                split = i;
                break;
            }
            max_right = max(max_right, s[i].r);
        }
        if (split == -1)
        {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < split; i++)
            s[i].group = 1;
        sort(s.begin(), s.end(), segment::comp_index);
        for (const segment &i : s)
            cout << i.group << " ";
        cout << endl;
    }
    return 0;
}