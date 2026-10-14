#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        bool zero_or_five = false;
        for (int &i : a)
        {
            cin >> i;
            if (i % 10 == 0 || i % 10 == 5)
                zero_or_five = true;
        }
        bool same = true;
        if (zero_or_five)
        {
            for (int &i : a)
            {
                if (i % 10 == 5)
                    i += 5;
            }
            for (int i = 1; i < n; i++)
            {
                if (a[i] != a[0])
                {
                    same = false;
                    break;
                }
            }
        }
        else
        {
            for (int &i : a)
            {
                while (i % 10 != 2)
                    i += i % 10;
            }
            for (int i = 1; i < n; i++)
            {
                if (a[i] % 20 != a[0] % 20)
                {
                    same = false;
                    break;
                }
            }
        }
        cout << (same ? "Yes" : "No") << endl;
    }
    return 0;
}