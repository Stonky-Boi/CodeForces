#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<long int> distinct_strings(n, 0);
        vector<int> next_position(26, n);
        distinct_strings[n - 1] = 1;
        next_position[s[n - 1] - 'a'] = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            distinct_strings[i] = distinct_strings[i + 1] + (next_position[s[i] - 'a'] - i);
            next_position[s[i] - 'a'] = i;
        }
        cout << distinct_strings[0] << endl;
    }
    return 0;
}