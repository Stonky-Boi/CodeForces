#include <iostream>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    bool reverse = true;
    if (s.size() != t.size())
        reverse = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != t[s.size() - i - 1])
            reverse = false;
            break;
    }
    if (reverse)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}