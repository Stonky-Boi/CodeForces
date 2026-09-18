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
        bool zero = false, one = false;
        for (char c : s)
        {
            if (c == '0' && !zero)
                zero = true;
            else if (c == '1' && !one)
                one = true;
            else
                cout << c;
        }
        cout << endl;
    }
    return 0;
}