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
        bool three_consecutive = false;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '.')
            {
                count++;
                if (i >= 2 && s[i - 1] == '.' && s[i - 2] == '.')
                {
                    three_consecutive = true;
                    break;
                }
            }
        }
        cout << (three_consecutive ? 2 : count) << endl;
    }
    return 0;
}