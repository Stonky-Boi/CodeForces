#include <iostream>
using namespace std;

int main()
{
    int t, n;
    string s;
    bool r = 1;
    cout << "Enter: " << endl;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] > s[i + 1])
            {
                r = false;
                break;
            }
            else
                r = true;
        }
        if (r)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}