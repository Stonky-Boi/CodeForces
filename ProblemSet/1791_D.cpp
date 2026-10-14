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
        vector<int> freq(26, 0), window(26, 0);
        for (const char &c : s)
            freq[c - 'a']++;
        int max_value = 1;
        for (const char &c : s)
        {
            window[c - 'a']++;
            freq[c - 'a']--;
            int curr_value = 0;
            for (int i = 0; i < 26; i++)
                curr_value += min(1, freq[i]) + min(1, window[i]);
            max_value = max(max_value, curr_value);
        }
        cout << max_value << endl;
    }
    return 0;
}