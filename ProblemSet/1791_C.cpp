#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        while ((s[0] == '0' && s[n - 1] == '1') || (s[0] == '1' && s[n - 1] == '0') && n > 1)
        {
            s = s.substr(1, n - 2);
            n = n - 2;
        }
        if (s == "0")
            n = 1;
        if (s == "")
            n = 0;
        cout << n << endl;
    }
    return 0;
}