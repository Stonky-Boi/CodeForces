#include <iostream>
using namespace std;

bool valid(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    int count = 0;
    for (int i = l; i <= r; i++)
    {
        int value;
        cin >> value;
        if (value >= l && value <= r)
            count++;
    }
    return count % 2 == 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int x;
        int l = 1, r = n;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (valid(l, m))
            {
                x = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        cout << "! " << x << endl;
    }
    return 0;
}