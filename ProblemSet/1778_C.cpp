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
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        vector<int> index(26, -1);
        vector<int> letters;
        for (const char &c : a)
        {
            if (index[c - 'a'] == -1)
            {
                index[c - 'a'] = letters.size();
                letters.push_back(c);
            }
        }
        int m = letters.size();
        long long pairs = 0;
        for (int mask = 0; mask < (1 << m); mask++)
        {
            if (__builtin_popcount(mask) != min(k, m))
                continue;
            long long curr = 0, length = 0;
            for (int i = 0; i < n; i++)
            {
                int x = index[a[i] - 'a'];
                if (a[i] == b[i] || (mask & (1 << x)))
                {
                    length++;
                    curr += length;
                }
                else
                    length = 0;
            }
            pairs = max(pairs, curr);
        }
        cout << pairs << endl;
    }
    return 0;
}