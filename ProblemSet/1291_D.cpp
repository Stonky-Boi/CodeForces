#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int prefix[200005][26] = {0};
    for (int i = 1; i <= s.length(); i++)
    {
        for (int ch = 0; ch < 26; ch++)
            prefix[i][ch] = prefix[i - 1][ch];
        prefix[i][s[i - 1] - 'a']++;
    }
    long int q;
    cin >> q;
    while (q--)
    {
        long int l, r;
        cin >> l >> r;
        bool irreducible = false;
        if (l == r)
            irreducible = true;
        else if (s[l - 1] != s[r - 1])
            irreducible = true;
        else
        {
            int distinct_letters = 0;
            for (int ch = 0; ch < 26; ch++)
            {
                if (prefix[r][ch] - prefix[l - 1][ch] > 0)
                    distinct_letters++;
            }
            if (distinct_letters >= 3)
                irreducible = true;
        }
        if (irreducible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}