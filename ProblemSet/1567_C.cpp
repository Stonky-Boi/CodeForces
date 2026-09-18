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
        string s1, s2;
        for (int i = 0; i < s.size(); i++)
        {
            if (i % 2 == 0)
                s1 += s[i];
            else
                s2 += s[i];
        }
        if (s2.empty())
        {
            cout << stoll(s1) - 1 << endl;
            continue;
        }
        long long a = stoll(s1), b = stoll(s2);
        cout << (a + 1) * (b + 1) - 2 << endl;
    }
    return 0;
}