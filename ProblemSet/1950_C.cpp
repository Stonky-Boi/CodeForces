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
        int hour = stoi(s.substr(0, 2));
        bool am = true;
        if (hour > 12)
        {
            hour -= 12;
            am = false;
        }
        else if (hour == 0)
            hour = 12;
        else if (hour == 12)
            am = false;
        cout << (hour < 10 ? "0" : "") << hour << s.substr(2, 3) << (am ? " AM" : " PM") << endl;
    }
    return 0;
}