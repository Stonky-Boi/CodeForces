#include <iostream>
using namespace std;

int main()
{
    string n;
    cin >> n;
    int lucky_digits = 0;
    for (int i = 0; i < n.size(); i++)
    {
        if (n[i] == '4' || n[i] == '7')
            lucky_digits++;
    }
    string s = to_string(lucky_digits);
    bool lucky = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '4' && s[i] != '7')
        {
            lucky = false;
            break;
        }
    }
    if (lucky)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}