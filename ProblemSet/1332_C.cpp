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
        int characters = 0;
        for (int i = 0; i < (k + 1) / 2; i++)
        {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j += k)
            {
                freq[s[j] - 'a']++;
                if (k - 1 - 2 * i != 0)
                    freq[s[j + (k - 1 - 2 * i)] - 'a']++;
            }
            int maximum = 0, total = 0;
            for (const int &f : freq)
            {
                maximum = max(maximum, f);
                total += f;
            }
            characters += total - maximum;
        }
        cout << characters << endl;
    }
    return 0;
}