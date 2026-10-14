#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        char c;
        string s;
        cin >> n >> c >> s;
        int different = 0;
        for (const char &ch : s)
        {
            if (ch != c)
                different++;
        }
        if (different == 0)
        {
            cout << 0 << endl;
            continue;
        }
        int x = -1;
        for (int i = 2; i <= n; i++)
        {
            bool possible = true;
            for (int j = i; j <= n; j += i)
            {
                if (s[j - 1] != c)
                {
                    possible = false;
                    break;
                }
            }
            if (possible)
            {
                x = i;
                break;
            }
        }
        if (x != -1)
        {
            cout << 1 << endl;
            cout << x << endl;
        }
        else
        {
            cout << 2 << endl;
            cout << n - 1 << " " << n << endl;
        }
    }
    return 0;
}