#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int a[26] = {0}, odd_letters = 0;
        for (int i = 0; i < n; i++)
            a[s[i] - 'a']++;
        for (int i = 0; i < 26; i++)
        {
            if (a[i] % 2 != 0)
                odd_letters++;
        }
        if (((odd_letters - k) == 1) || (odd_letters == 0) || (odd_letters == 1) || (k >= odd_letters))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}