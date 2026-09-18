#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, l, r;
        cin >> n >> m >> l >> r;
        if (l == 0)
            cout << "0 " << m << endl;
        else if (r == 0)
            cout << -m << " 0" << endl;
        else
        {
            int minimum = min(-l, r);
            if (m <= 2 * minimum)
            {
                int half = m / 2;
                if (m % 2 == 0)
                    cout << -half << " " << half << endl;
                else
                    cout << -half << " " << half + 1 << endl;
            }
            else
            {
                if (-l < r)
                    cout << l << " " << m + l << endl;
                else
                    cout << r - m << " " << r << endl;
            }
        }
    }
    return 0;
}