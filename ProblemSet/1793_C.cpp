#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        int l = 0, r = n - 1;
        int minimum = 1, maximum = n;
        while (l <= r)
        {
            if (a[l] == minimum)
            {
                l++;
                minimum++;
            }
            else if (a[l] == maximum)
            {
                l++;
                maximum--;
            }
            else if (a[r] == minimum)
            {
                r--;
                minimum++;
            }
            else if (a[r] == maximum)
            {
                r--;
                maximum--;
            }
            else
                break;
        }
        if (l <= r)
            cout << l + 1 << " " << r + 1 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}