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
        if (a[n - 2] > a[n - 1])
        {
            cout << -1 << endl;
            continue;
        }
        if (a[n - 1] >= 0)
        {
            cout << n - 2 << endl;
            for (int i = 1; i <= n - 2; i++)
                cout << i << " " << n - 1 << " " << n << endl;
        }
        else
        {
            bool sorted = true;
            for (int i = 1; i < n; i++)
            {
                if (a[i - 1] > a[i])
                {
                    sorted = false;
                    break;
                }
            }
            cout << (sorted ? 0 : -1) << endl;
        }
    }
    return 0;
}