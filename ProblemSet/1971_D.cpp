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
        int pieces = 1;
        bool transition_found = false;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != s[i - 1])
            {
                pieces++;
                transition_found = true;
            }
        }
        if (transition_found && s.find("01") != string::npos)
            pieces--;
        cout << pieces << endl;
    }
    return 0;
}