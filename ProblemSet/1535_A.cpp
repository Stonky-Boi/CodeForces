#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int s[4];
        for (int i = 0; i < 4; i++)
            cin >> s[i];
        int finalist_1 = max(s[0], s[1]), finalist_2 = max(s[2], s[3]);
        sort(s, s + 4);
        if ((finalist_1 == s[3] && finalist_2 == s[2]) || (finalist_1 == s[2] && finalist_2 == s[3]))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}