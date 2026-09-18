#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n;
        cin >> n;
        long long int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int minimum = 0, maximum = INT_MAX;
        for (int i = 0; i + 1 < n; i++)
        {
            int x = a[i];
            int y = a[i + 1];
            int middle_floor = (x + y) / 2;
            int middle_ceil = (x + y + 1) / 2;
            if (x < y)
                maximum = min(maximum, middle_floor);
            if (x > y)
                minimum = max(minimum, middle_ceil);
        }
        if (minimum <= maximum)
            cout << minimum << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}