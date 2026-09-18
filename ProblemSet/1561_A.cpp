#include <iostream>
using namespace std;

bool is_sorted(int a[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        if (a[i - 1] > a[i])
            return false;
    }
    return true;
}

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
        int iteration = 0;
        while (!is_sorted(a, n))
        {
            iteration++;
            for (int i = (iteration % 2 == 1 ? 0 : 1); i < n - 1; i += 2)
            {
                if (a[i] > a[i + 1])
                {
                    a[i] = a[i] + a[i + 1];
                    a[i + 1] = a[i] - a[i + 1];
                    a[i] = a[i] - a[i + 1];
                }
            }
        }
        cout << iteration << endl;
    }
    return 0;
}