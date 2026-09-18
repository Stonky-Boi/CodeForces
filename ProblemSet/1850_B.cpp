#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, max_quality = 0;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i] >> b[i];
        for (int i = 0; i < n; i++)
        {
            if (a[i] <= 10)
            {
                if (b[i] > max_quality)
                {
                    max_quality = b[i];
                    x = i;
                }
            }
        }
        cout << x + 1 << endl;
    }
    return 0;
}