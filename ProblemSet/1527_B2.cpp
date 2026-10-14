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
        bool palindrome = true;
        int zeroes = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != s[n - i - 1])
                palindrome = false;
            if (s[i] == '0')
                zeroes++;
        }
        if (palindrome)
            cout << (zeroes == 1 || zeroes % 2 == 0 ? "BOB" : "ALICE") << endl;
        else
            cout << (zeroes == 2 && n % 2 == 1 && s[n / 2] == '0' ? "DRAW" : "ALICE") << endl;
    }
    return 0;
}