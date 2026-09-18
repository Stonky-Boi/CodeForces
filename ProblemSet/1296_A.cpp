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
        bool odd_number_exists = false, even_number_exists = false;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 != 0)
                odd_number_exists = true;
            else
                even_number_exists = true;
        }
        if (n % 2 != 0)
        {
            if (odd_number_exists)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            if (odd_number_exists && even_number_exists)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}