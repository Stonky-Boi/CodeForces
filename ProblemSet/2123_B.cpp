#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n, j, k;
        cin >> n >> j >> k;
        long int a[n];
        long int max = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > max)
                max = a[i];
        }
        if (a[j - 1] != max && k == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}