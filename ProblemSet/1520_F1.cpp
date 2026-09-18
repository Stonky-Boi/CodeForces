#include <iostream>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    while (t--)
    {
        int k;
        cin >> k;
        int sum, l = 1, r = n;
        while (l <= r)
        {
            if (l == r)
            {
                cout << "! " << l << endl;
                break;
            }
            int m = (l + r) / 2;
            cout << "? " << l << " " << m << endl;
            cin >> sum;
            int left_zeroes = (m - l + 1) - sum;
            if (left_zeroes >= k)
                r = m;
            else
            {
                k -= left_zeroes;
                l = m + 1;
            }
        }
    }
    return 0;
}