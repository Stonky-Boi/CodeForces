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
        int differences = 0;
        string reference = "codeforces";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != reference[i])
                differences++;
        }
        cout << differences << endl;
    }
    return 0;
}