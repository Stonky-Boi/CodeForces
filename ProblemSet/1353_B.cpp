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
        int a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < k; i++)
        {
            sort(a, a + n);
            sort(b, b + n);
            if (a[0] < b[n - 1])
            {
                a[0] = a[0] + b[n - 1];
                b[n - 1] = a[0] - b[n - 1];
                a[0] = a[0] - b[n - 1];
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += a[i];
        cout << sum << endl;
    }
    return 0;
}