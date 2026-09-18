#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        bool ascending = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                ascending = false;
                break;
            }
        }
        if ((k == 1) && (!ascending))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}