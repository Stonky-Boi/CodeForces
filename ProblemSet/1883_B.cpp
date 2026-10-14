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
        vector<int> freq(26, 0);
        for (const char &c : s)
            freq[c - 'a']++;
        int odd_count = 0;
        for (const int &f : freq)
        {
            if (f % 2 != 0)
                odd_count++;
        }
        cout << (k + 1 < odd_count ? "NO" : "YES") << endl;
    }
    return 0;
}