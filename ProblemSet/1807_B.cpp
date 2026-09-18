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
        int mihai = 0, bianca = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
                mihai += a[i];
            else
                bianca += a[i];
        }
        if (mihai > bianca)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}