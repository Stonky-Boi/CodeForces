#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        bool possible = true;
        for (int j = k; j < n; j++)
        {
            int i = j % k;
            if (s[j] == '?')
                continue;
            if (s[i] == '?')
                s[i] = s[j];
            else if (s[i] != s[j])
            {
                possible = false;
                break;
            }
        }
        if (!possible)
        {
            cout << "NO" << endl;
            continue;
        }
        int zeroes = 0, ones = 0;
        for (int i = 0; i < k; i++)
        {
            if (s[i] == '0')
                zeroes++;
            else if (s[i] == '1')
                ones++;
        }
        cout << (zeroes > k / 2 || ones > k / 2 ? "NO" : "YES") << endl;
    }
    return 0;
}