#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, even_count = 0, odd_count = 0;
        cin >> n;
        int a[2 * n];
        for (int i = 0; i < 2 * n; i++)
            cin >> a[i];
        for (int i = 0; i < 2 * n; i++)
        {
            if (a[i] % 2 == 0)
                even_count++;
            else
                odd_count++;
        }
        if (even_count == odd_count)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}