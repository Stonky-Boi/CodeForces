#include <iostream>
#include <vector>
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
        vector<int> freq(26, 0);
        int distinct = 0, count = 0;
        for (const char &c : s)
        {
            if (freq[c - 'a'] == 0)
                count++;
            freq[c - 'a']++;
            distinct += count;
        }
        cout << distinct << endl;
    }
    return 0;
}