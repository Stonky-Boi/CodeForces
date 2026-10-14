#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, m;
        cin >> n >> x >> m;
        int left = x, right = x;
        while (m--)
        {
            int l, r;
            cin >> l >> r;
            if (l <= right && r >= left)
            {
                left = min(left, l);
                right = max(right, r);
            }
        }
        cout << right - left + 1 << endl;
    }
    return 0;
}