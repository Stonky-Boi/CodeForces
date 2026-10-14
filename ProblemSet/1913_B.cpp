#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int zeroes = 0, ones = 0;
        for (const char &c : s)
        {
            if (c == '0')
                zeroes++;
            else
                ones++;
        }
        int length = 0;
        for (const char &c : s)
        {
            if (c == '0' && ones > 0)
            {
                length++;
                ones--;
            }
            else if (c == '1' && zeroes > 0)
            {
                length++;
                zeroes--;
            }
            else
                break;
        }
        cout << s.size() - length << endl;
    }
    return 0;
}