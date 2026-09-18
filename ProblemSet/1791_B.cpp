#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n;
        cin >> s;
        int x_coordinate = 0, y_coordinate = 0;
        bool pass = false;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L')
                x_coordinate--;
            else if (s[i] == 'R')
                x_coordinate++;
            else if (s[i] == 'U')
                y_coordinate++;
            else if (s[i] == 'D')
                y_coordinate--;
            if (x_coordinate == 1 && y_coordinate == 1)
            {
                pass = true;
                break;
            }
        }
        if (pass)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}