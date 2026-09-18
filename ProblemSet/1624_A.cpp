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
        int a[n], max = 0, min = 1000000000;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (max < a[i])
                max = a[i];
            if (min > a[i])
                min = a[i];
        }
        cout << max - min << endl;
    }
    return 0;
}