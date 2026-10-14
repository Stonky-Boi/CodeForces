#include <iostream>
#include <vector>
using namespace std;

bool valid(vector<int> &a, int x, int h)
{
    long long water = 0;
    for (const int &i : a)
        water += max(0, h - i);
    return water <= x;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        int l = 0, r = 2e9;
        int maximum = 0;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (valid(a, x, m))
            {
                maximum = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        cout << maximum << endl;
    }
    return 0;
}