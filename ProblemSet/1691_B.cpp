#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> s(n);
        for (int &i : s)
            cin >> i;
        map<int, int> freq;
        for (const int &i : s)
            freq[i]++;
        bool possible = true;
        for (const auto &[_, f] : freq)
        {
            if (f == 1)
            {
                possible = false;
                break;
            }
        }
        if (!possible)
        {
            cout << -1 << endl;
            continue;
        }
        vector<int> order(n);
        for (int i = 0; i < n; i++)
            order[i] = i + 1;
        int l = 0, r = 0;
        while (r < n)
        {
            if (s[l] == s[r])
                r++;
            else
            {
                rotate(order.begin() + l, order.begin() + l + 1, order.begin() + r);
                l = r;
            }
        }
        rotate(order.begin() + l, order.begin() + l + 1, order.begin() + r);
        for (const int &i : order)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}