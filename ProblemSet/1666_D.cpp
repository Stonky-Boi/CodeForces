#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        int n = s.size();
        vector<int> frequency(26, 0);
        for (const char &c : t)
            frequency[c - 'A']++;
        for (int i = n - 1; i >= 0; i--)
        {
            if (frequency[s[i] - 'A'] > 0)
                frequency[s[i] - 'A']--;
            else
                s[i] = '.';
        }
        string final = "";
        for (const char &c : s)
        {
            if (c != '.')
                final += c;
        }
        cout << (final == t ? "YES" : "NO") << endl;
    }
    return 0;
}