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
        long int b[n], a[n];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i <= n / 2; i++)
        {
            a[2 * i] = b[i];
            a[2 * i + 1] = b[n - i - 1];
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}