#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m = n / 2;
        vector<int> b(m), p(n);
        set<int> seen;
        bool possible = true;
        for (int &i : b)
        {
            cin >> i;
            if (seen.find(i) != seen.end())
                possible = false;
            seen.insert(i);
        }
        set<int> unused;
        for (int i = 1; i <= n; i++)
        {
            if (seen.find(i) == seen.end())
                unused.insert(i);
        }
        for (int i = m - 1; i >= 0 && possible; i--)
        {
            auto it = unused.lower_bound(b[i]);
            if (it == unused.begin())
            {
                possible = false;
                break;
            }
            it--;
            p[2 * i] = *it;
            p[2 * i + 1] = b[i];
            unused.erase(it);
        }
        if (!possible)
            cout << -1 << endl;
        else
        {
            for (const int &i : p)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}