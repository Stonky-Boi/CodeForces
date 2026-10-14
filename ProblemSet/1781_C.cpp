#include <iostream>
#include <vector>
#include <algorithm>
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
        vector<int> freq(26);
        for (const char &c : s)
            freq[c - 'a']++;
        int max_matches = -1;
        string final;
        vector<int> letters(26);
        for (int i = 0; i < 26; i++)
            letters[i] = i;
        sort(letters.begin(), letters.end(), [&](int a, int b)
             { return freq[a] > freq[b]; });
        for (int k = 1; k <= 26; k++)
        {
            if (n % k != 0)
                continue;
            int need = n / k;
            vector<bool> chosen(26, false);
            for (int i = 0; i < k; i++)
                chosen[letters[i]] = true;
            vector<int> count(26, need);
            string curr(n, '?');
            int matches = 0;
            for (int i = 0; i < n; i++)
            {
                int c = s[i] - 'a';
                if (chosen[c] && count[c])
                {
                    curr[i] = s[i];
                    count[c]--;
                    matches++;
                }
            }
            int j = 0;
            for (int i = 0; i < n; i++)
            {
                if (curr[i] != '?')
                    continue;
                while (count[letters[j]] == 0)
                    j++;
                curr[i] = 'a' + letters[j];
                count[letters[j]]--;
            }
            if (matches > max_matches)
            {
                max_matches = matches;
                final = curr;
            }
        }
        cout << n - max_matches << endl;
        cout << final << endl;
    }
}