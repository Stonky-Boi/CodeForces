#include <iostream>
using namespace std;

int match(char a, char b)
{
    return a == '?' || b == '?' || a == b ? 1 : 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int max_length = 0;
        for (int length = 1; length * 2 <= n; length++)
        {
            int count = 0;
            for (int i = 0; i < length; i++)
                count += match(s[i], s[i + length]);
            if (count == length)
                max_length = 2 * length;
            for (int i = 1; i + 2 * length <= n; i++)
            {
                count -= match(s[i - 1], s[i + length - 1]);
                count += match(s[i + length - 1], s[i + 2 * length - 1]);
                if (count == length)
                    max_length = 2 * length;
            }
        }
        cout << max_length << endl;
    }
    return 0;
}