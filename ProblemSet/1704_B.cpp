#include <iostream>
#include <vector>
using namespace std;

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
        int changes = 0;
        int l = 0, r = 1e9;
        for (const int &i : a)
        {
            l = max(l, i - x);
            r = min(r, i + x);
            if (l > r)
            {
                changes++;
                l = i - x;
                r = i + x;
            }
        }
        cout << changes << endl;
    }
    return 0;
}