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
        bool satisfy = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (a[i] == a[j])
                {
                    satisfy = false;
                    break;
                }
            }
        }
        if (satisfy)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}