#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (a[0] != a[1] && a[0] != a[2])
            cout << 1 << endl;
        else if (a[n - 1] != a[n - 2] && a[n - 1] != a[n - 3])
            cout << n << endl;
        else
        {
            for (int i = 1; i < n - 1; i++)
            {
                if (a[i] != a[i - 1] && a[i] != a[i + 1])
                {
                    cout << i + 1 << endl;
                    break;
                }
            }
        }
    }
    return 0;
}