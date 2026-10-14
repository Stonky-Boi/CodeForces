#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        bool possible = true;
        for (int i = 1; i <= n; i++)
        {
            a[i - 1] = ((l + i - 1) / i) * i;
            if (a[i - 1] > r)
            {
                possible = false;
                break;
            }
        }
        if (possible)
        {
            cout << "YES" << endl;
            for (const int &i : a)
                cout << i << " ";
            cout << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}