#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int need = n / 2;
        for (const char &c : s)
        {
            if (c == '(')
                need--;
        }
        int last_open = -1, first_close = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '?')
            {
                if (need > 0)
                {
                    s[i] = '(';
                    need--;
                    last_open = i;
                }
                else
                {
                    s[i] = ')';
                    if (first_close == -1)
                        first_close = i;
                }
            }
        }
        if (last_open == -1 || first_close == -1)
        {
            cout << "YES" << endl;
            continue;
        }
        s[last_open] = ')';
        s[first_close] = '(';
        int balance = 0;
        bool valid = true;
        for (const char &c : s)
        {
            if (c == '(')
                balance++;
            else
                balance--;
            if (balance < 0)
            {
                valid = false;
                break;
            }
        }
        cout << (valid ? "NO" : "YES") << endl;
    }
    return 0;
}