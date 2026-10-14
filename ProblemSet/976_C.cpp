#include <iostream>
#include <vector>
#include <algorithm>
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

int main()
{
    int n;
    cin >> n;
    vector<segment> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].l >> s[i].r;
        s[i].index = i;
    }
    sort(s.begin(), s.end());
    int max_r = 0;
    int max_index = -1;
    bool possible = false;
    for (const auto &[_, r, i] : s)
    {
        if (r <= max_r)
        {
            cout << i + 1 << " " << max_index + 1 << endl;
            possible = true;
            break;
        }
        if (r > max_r)
        {
            max_r = r;
            max_index = i;
        }
    }
    if (!possible)
        cout << "-1 -1" << endl;
    return 0;
}