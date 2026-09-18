#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        if (str.size() % 2 != 0)
            cout << "NO" << endl;
        else if (str.substr(0, str.size() / 2) == str.substr(str.size() / 2, str.size() / 2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}