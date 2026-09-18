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
        int a[n], even_wrong = 0, odd_wrong = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 0 && i % 2 != 0)
                even_wrong++;
            if (a[i] % 2 == 1 && i % 2 != 1)
                odd_wrong++;
        }
        if (odd_wrong != even_wrong)
            cout << "-1" << endl;
        else
            cout << (even_wrong + odd_wrong) / 2 << endl;
    }
    return 0;
}