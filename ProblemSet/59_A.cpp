#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int upper_count = 0, lower_count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int c = (int)s[i];
        if (c > 64 && c < 91)
            upper_count++;
        if (c > 96 && c < 123)
            lower_count++;
    }
    if (upper_count > lower_count)
    {
        for (int i = 0; i < s.size(); i++)
        {
            int c = (int)s[i];
            if (c > 96 && c < 123)
                c -= 32;
            s[i] = (char)c;
        }
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            int c = (int)s[i];
            if (c > 64 && c < 91)
                c += 32;
            s[i] = (char)c;
        }
    }
    cout << s << endl;
    return 0;
}